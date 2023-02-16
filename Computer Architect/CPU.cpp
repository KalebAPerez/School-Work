/******************************
 * Submitted by: Kaleb Perez kap222
 * CS 3339 - Spring 2022, Texas State University
 * Project 2 Emulator
 * Copyright 2021, Lee B. Hinkle, all rights reserved
 * Based on prior work by Martin Burtscher and Molly O'Neil
 * Redistribution in source or binary form, with or without modification,
 * is *not* permitted. Use in source or binary form, with or without
 * modification, is only permitted for academic use in CS 3339 at
 * Texas State University.
 ******************************/

#include "CPU.h"

const string CPU::regNames[] = {"$zero","$at","$v0","$v1","$a0","$a1","$a2","$a3",
                                "$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7",
                                "$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7",
                                "$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"};

CPU::CPU(uint32_t pc, Memory &iMem, Memory &dMem) : pc(pc), iMem(iMem), dMem(dMem) {
  for(int i = 0; i < NREGS; i++) {
    regFile[i] = 0;
  }
  hi = 0;
  lo = 0;
  regFile[28] = 0x10008000; // gp
  regFile[29] = 0x10000000 + dMem.getSize(); // sp

  instructions = 0;
  stop = false;
}

void CPU::run() {
  while(!stop) {
    instructions++;

    fetch();
    decode();
    execute();
    mem();
    writeback();

    D(printRegFile());
  }
}

void CPU::fetch() {
  instr = iMem.loadWord(pc);
  pc = pc + 4;
}

/////////////////////////////////////////
// ALL YOUR CHANGES GO IN THIS FUNCTION 
/////////////////////////////////////////
void CPU::decode() {
  uint32_t opcode;      // opcode field
  uint32_t rs, rt, rd;  // register specifiers
  uint32_t shamt;       // shift amount (R-type)

  uint32_t funct;       // funct field (R-type)
  uint32_t uimm;        // unsigned version of immediate (I-type)
  int32_t simm;         // signed version of immediate (I-type)
  uint32_t addr;        // jump address offset field (J-type
//opcode - funct are shifted to align right then masked
opcode = (instr >> 26);
rs = (instr >> 21) & 0x1f;
rt = (instr >> 16) & 0x1f;
rd = (instr >> 11) & 0x1f;
shamt = (instr >> 6) & 0x1f;
funct = (instr &  0x3f);
  
// signed immediate moved 16 bits left, then back to repeat the sign
uimm = instr << 16 >> 16;
simm = (signed)(instr) << 16 >> 16;
addr =(instr & 0x3ffffff); 

  // Hint: you probably want to give all the control signals some "safe"
  // default value here, and then override their values as necessary in each
  // case statement below!
opIsLoad = false;
opIsStore = false;
opIsMultDiv = false;
writeDest = false;


  D(cout << "  " << hex << setw(8) << pc - 4 << ": ");
  switch(opcode) {
    case 0x00:
      switch(funct) {
        case 0x00: D(cout << "sll " << regNames[rd] << ", " << regNames[rs] << ", " << dec << shamt);
                   writeDest = true; destReg = rd; //for operations that write, include writedest true and dest
                   aluOp = SHF_L;//says shift left in name
                   aluSrc1 = regFile[rs];
                   aluSrc2 = shamt;
                   break; // use prototype above, not the greensheet
        case 0x03: D(cout << "sra " << regNames[rd] << ", " << regNames[rs] << ", " << dec << shamt);
                   writeDest = true; destReg = rd;
                   aluOp = SHF_R;//says shift right in name
                   aluSrc1 = regFile[rs];
                   aluSrc2 = shamt;
                   break; // use prototype above, not the greensheet
        case 0x08: D(cout << "jr " << regNames[rs]);
                
                   pc = regFile[rs];
                   break;
        case 0x10: D(cout << "mfhi " << regNames[rd]);
                   writeDest = true; destReg = rd;
                   aluOp = ADD;
                   aluSrc1 = hi;
                   aluSrc2 = regFile[REG_ZERO];
                   break;
        case 0x12: D(cout << "mflo " << regNames[rd]);
                   writeDest = true; destReg = rd;
                   aluOp = ADD;
                   aluSrc1 = lo;
                   aluSrc2 = regFile[REG_ZERO];
                   break;
        case 0x18: D(cout << "mult " << regNames[rs] << ", " << regNames[rt]);//all of these middle ones are similar
                    
                   opIsMultDiv = true;
                   aluOp = MUL;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt];
                   break;
        case 0x1a: (cout << "div " << regNames[rs] << ", " << regNames[rt]);
                   //writeDest = true; destReg= REG_HILO;
                   opIsMultDiv = true;
                   aluOp = DIV;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt];
                   break;
        case 0x21: D(cout << "addu " << regNames[rd] << ", " << regNames[rs] << ", " << regNames[rt]);
                   writeDest = true; destReg = rd;
                   aluOp = ADD;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt];
                   break;
        case 0x23: D(cout << "subu " << regNames[rd] << ", " << regNames[rs] << ", " << regNames[rt]);
                   writeDest = true; destReg = rd;
                   aluOp = ADD;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = -1 * regFile[rt];//make file negative, like adding a negative
                   break; //hint: subtract is the same as adding a negative
        case 0x2a: D(cout << "slt " << regNames[rd] << ", " << regNames[rs] << ", " << regNames[rt]);
                   writeDest = true; destReg = rd;
                   aluOp = CMP_LT;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt]; 
                   break;
        default: cerr << "unimplemented instruction: pc = 0x" << hex << pc - 4 << endl;
      }
      break;
    case 0x02: D(cout << "j " << hex << ((addr<<2) & 0xffffff)); // P1: pc + 
               aluOp = ADD;
	       aluSrc1 = pc;
	       aluSrc2 = regFile[REG_ZERO];
               pc = (pc & 0xf0000000) | addr << 2;
               break;
    case 0x03: D(cout << "jal " << hex << ((pc & 0xf0000000) | addr << 2)); // P1: pc + 4
               writeDest = true; destReg = REG_RA; // writes PC+4 to $ra
               aluOp = ADD; //ALU should pass pc thru unchanged
               aluSrc1 = pc;
               aluSrc2 = regFile[REG_ZERO]; // always reads zero
               pc = (pc & 0xf0000000) | addr << 2;
               break;
    case 0x04: D(cout << "beq " << regNames[rs] << ", " << regNames[rt] << ", " << pc + (simm << 2));
               //aluOp = ADD;
               //aluSrc1 = pc;
               //aluSrc2 = regFile[REG_ZERO];
               if(regFile[rs] == regFile[rt]) ;//this is branch
               {
               
                  pc = pc + (simm << 2); //pc moves to new spot in branch
               }               


               break;  // read the handout carefully, update PC directly here as in jal example
    case 0x05: D(cout << "bne " << regNames[rs] << ", " << regNames[rt] << ", " << pc + (simm << 2));
               //aluOp = ADD;
               //aluSrc1 = pc;
               //aluSrc2 = regFile[REG_ZERO];
               if (regFile[rs] != regFile[rt])//this is the branch 
               { 
              
                  pc = (pc + (simm << 2));
 
               }
               break;  // same comment as beq
    case 0x09: D(cout << "addiu " << regNames[rt] << ", " << regNames[rs] << ", " << dec << simm);
               writeDest = true; destReg = rt;
               aluOp = ADD;
               aluSrc1 = regFile[rs];
               aluSrc2 = simm;
               break;
    case 0x0c: D(cout << "andi " << regNames[rt] << ", " << regNames[rs] << ", " << dec << uimm);
               writeDest = true; destReg = rt;
               aluOp = AND;
               aluSrc1 = regFile[rs];
               aluSrc2 = uimm;
               break;
    case 0x0f: D(cout << "lui " << regNames[rt] << ", " << dec << simm);
               writeDest = true; destReg = rt;
               aluOp = ADD;
               aluSrc1 = simm << 16;
               aluSrc2 = regFile[REG_ZERO];
               break; //use the ALU to execute necessary op, you may set aluSrc2 = xx directly
    case 0x1a: D(cout << "trap " << hex << addr);
               switch(addr & 0xf) {
                 case 0x0: cout << endl; break;
                 case 0x1: cout << " " << (signed)regFile[rs];
                           break;
                 case 0x5: cout << endl << "? "; cin >> regFile[rt];
                           break;
                 case 0xa: stop = true; break;
                 default: cerr << "unimplemented trap: pc = 0x" << hex << pc - 4 << endl;
                          stop = true;
               }
               break;
    case 0x23: D(cout << "lw " << regNames[rt] << ", " << dec << simm << "(" << regNames[rs] << ")");
               writeDest = true; destReg = rt;
               opIsLoad = true;
               aluOp = ADD;
               aluSrc1 = regFile[REG_ZERO];
               aluSrc2 = regFile[rs]+simm;
             
               break;  // do not interact with memory here - setup control signals for mem()
    case 0x2b: D(cout << "sw " << regNames[rt] << ", " << dec << simm << "(" << regNames[rs] << ")");

               writeDest = false; 
               opIsStore = true;//same as lw jsut with storing
           
               aluOp = ADD;
               aluSrc1 = simm;
               aluSrc2  = regFile[rs];
               storeData = regFile[rt];
            
               break;  // same comment as lw
    default: cerr << "unimplemented instruction: pc = 0x" << hex << pc - 4 << endl;
  }
  D(cout << endl);
}

void CPU::execute() {
  aluOut = alu.op(aluOp, aluSrc1, aluSrc2);
}

void CPU::mem() {
  if(opIsLoad)
    writeData = dMem.loadWord(aluOut);
  else
    writeData = aluOut;

  if(opIsStore)
    dMem.storeWord(storeData, aluOut);
}

void CPU::writeback() {
  if(writeDest && destReg > 0) // skip when write is to zero_register
    regFile[destReg] = writeData;
  
  if(opIsMultDiv) {
    hi = alu.getUpper();
    lo = alu.getLower();
  }
}

void CPU::printRegFile() {
  cout << hex;
  for(int i = 0; i < NREGS; i++) {
    cout << "    " << regNames[i];
    if(i > 0) cout << "  ";
    cout << ": " << setfill('0') << setw(8) << regFile[i];
    if( i == (NREGS - 1) || (i + 1) % 4 == 0 )
      cout << endl;
  }
  cout << "    hi   : " << setfill('0') << setw(8) << hi;
  cout << "    lo   : " << setfill('0') << setw(8) << lo;
  cout << dec << endl;
}

void CPU::printFinalStats() {
  cout << "Program finished at pc = 0x" << hex << pc << "  ("
       << dec << instructions << " instructions executed)" << endl;
}
