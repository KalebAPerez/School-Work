###############################################################################
# Title: Assign02P3                   Author: Kaleb Perez
# Class: CS 2318-25?, Spring 2022     Submitted: 04-9-2022
###############################################################################
# Program: MIPS tranlation of a given C++ program
###############################################################################
# Pseudocode description: supplied a2p2_SampSoln.cpp
###############################################################################





#include <iostream>
#using namespace std;

#int a1[11],

#    a3[11];
#char einStr[]    = "Enter integer #";
#char moStr[]     = "Max of ";
#char ieStr[]     = " ints entered...";
#char emiStr[]    = "Enter more ints? (n or N = no, others = yes) ";
#char begA1Str[]  = "beginning a1: ";
#char procA1Str[] = "processed a1: ";
#char commA2Str[] = "          a2: ";
#char commA3Str[] = "          a3: ";
#char dacStr[]    = "Do another case? (n or N = no, others = yes) ";
#char dlStr[]     = "================================";
#char byeStr[]    = "bye...";
.data
a1:		.space 11
a2:		.space 11
a3:		.space 11
einStr:		.asciiz "Enter integer #"
moStr:		.asciiz " ints entered..."
ieStr:		.asciiz "Enter more ints? (n or N = no, others = yes) "
emiStr:		.asciiz "Enter more ints? (n or N = no, others = yes) "
begA1Str:  	.asciiz "beginning a1: "
procA1Str: 	.asciiz "processed a1: "
commA2Str:  	.asciiz "          a2: "
commA3Str:  	.asciiz "          a3: "
dacStr:     	.asciiz "Do another case? (n or N = no, others = yes) "
dlStr:      	.asciiz "================================"
byeStr:    	.asciiz "bye..."
space:		.asciiz "\n"


#int main()
.text
.global main
main:
#{
 #              char input;
#               int  key;
 #              int  avg;
#               int  size1;
#               int  size2;
#               int  size3;
#               int  sum;
#               int* hopPtr1;
#               int* hopPtr2;
#               int* hopPtr21;
#               int* hopPtr3;
#               int* endPtr1;
#               int* endPtr2;
#               int* endPtr3;
#
#              cout << endl;
		li $v0, 11
		li $a0, '\n'
		syscall
#               input = 'y';
		li $v1, 'y'
#               //while (input != 'n' && input != 'N')
#              goto WTest1;
		j w1test
begw1:
#begW1://       {
#                  size1 = 0;
#                  size2 = 0;
#                  size3 = 0;
		li $t1, 0
		li $t2, 0
		li $t3, 0
#                  hopPtr1 = a1;
		
		la $t5, a1
		
#                  //while (input != 'n' && input != 'N')
#                  goto WTest2;
		j wtest2
#begW2://          {
begw2:
#                     cout << einStr;
		li $v0, 4
		la $a0, einStr
		syscall
#                     cout << (size1 + 1);
		addi $t1, $t1, 1
		li $v0, 1
		move $a0, $t1
		syscall
#                     cout << ':' << ' ';
		li $v0, 11
		li $a0, ':'
		syscall
		li $v0, 11
		li $a0, ' '
		syscall
		
#                     cin >> *hopPtr1;
		li $v0, 5
		syscall
		sw $v0, 0($t5)
#                     ++size1;
		addi $t1, $t1, 1
#                     ++hopPtr1;
		addi $t5, $t5, 4
#                     //if (size1 < 11)
#                     if (size1 >= 11) goto elseI1;
		li $s0, 11
		slt $t0, $s0, $t1
		beqz $t0, elsei1
		beq $s0, $t1, elsei1
#begI1://             {
begi1:
#                        cout << emiStr;
		li $v0, 4
		la $a0, emiStr
		syscall
#                        cin >> input;
		li $v0, 12
		syscall
		sw $v0, 0($v1)
#                     goto endI1;
		j endi1
#//                   }
#elseI1://             else
elsei1:
#//                   {
#                        cout << moStr << 11 << ieStr << endl;
#                        input = 'n
		li $v0, 4
		la $a0, moStr
		syscall
		li $v0, 1
		li $a0, 11
		syscall
		li $v0, 4
		la $a0, ieStr
		syscall
		li $v0,11
		li $a0, '\n'
		syscall
		li $v1, 'n'
#endI1://             }
endi1:
#WTest2://         }
wtest2:
#                  ////if (input != 'n' && input != 'N') goto begW2;
#                  if (input == 'n') goto xitW2;
#                  if (input != 'N') goto begW2;
		li $t0, 'n'
		beq $v1, $t0, xitw2
		li $t0, 'N'
		bne $v1, $t0, begw2
		
#xitW2:
xitw2:
#                  cout << endl;
		li $v0, 11
		li $a0, '\n'
		syscall
		
#
#                  //if (size1 > 0)
#                  if (size1 <= 0) goto endI2;
		
		blez $t1, endi2
		
#begI2://   {
begi2:       
#                     sum = 0;
		li $t0, 0
 #                    //for (hopPtr1 = a1, endPtr1 = a1 + size1; hopPtr1 < endPtr1; ++hopPtr1)
#                     hopPtr1 = a1;]
		la $t5, a1
 #                    endPtr1 = a1 + size1;
 		la $t0, a1
 		sll $s0, $t1, 4
 		add $a1, $t0, $s0
 		
#                     goto FTest1;
		j ftest1
		
#begF1://   {
begf1:          
#                        key = *hopPtr1;
		move $t4, $t1
#                        sum += key;
		add $t9, $t9, $t4
		 
#                        //if (key % 2 == 1)
#                        ////if (key % 2 != 1) goto elseI3;
#                        if ( (key & 1) != 1) goto elseI3;
		li $s0, 1
		andi $t0, $t4, 1
		bne $t0, $s0, elsei3
#begI3://   {
begi3:             
#                           hopPtr3 = a3 + size3 - 1;
		la $t0, a3
		sll $s0, $t0, 2
		add $t7, $s0, $t0
#                           endPtr3 = a3;
		la $a3, a3
#                           //while (hopPtr3 >= endPtr3)
#                           goto WTest3;
		j wtest3
#begW3://  {
begw3:                 
#                              //if (*hopPtr3 > key)
#                              if (*hopPtr3 <= key) goto elseI4;
		slt $t0, $t7, $t4
		bltz $t0, elsei4
		beq $t7, $t4, elsei4
#begI4://                      {
begi4:
#                                 *(hopPtr3 + 1) = *hopPtr3;
		addi $t0, $t7, 4
		sw $t7, 0($t0)
#                                 --hopPtr3;
		addi $t7, $t7, -4
#                              goto endI4;
		j endi4
#//                            }
#elseI4://                      else
elsei4:
#//                            {
#                                 //break;
#                                 goto brk1;
		j brk1
#endI4://                      }
endi4:
#WTest3://                  }
wtest3:
#                           if (hopPtr3 >= endPtr3) goto begW3;
		slt $t0, $a3, $t7
		bgez $t0, begw3
		beq $a3, $t7, begw3
#brk1:
brk1:
#                           *(hopPtr3 + 1) = key;
		addi $t0, $t7, 4
		sw $t4, 0($t0)
 #                          ++size3;
 		addi $t3, $t3, 1
#                        goto endI3;
		j endi3
#//                      }
#elseI3://                else
elsei3:
#//                      {
#                           hopPtr2 = a2;
		la $t6, a2
#                           endPtr2 = a2 + size2;
		la $s0, a2
		add $t0, $s0, $t2
		move $a2, $t0
#                           //while (hopPtr2 < endPtr2)
#                           goto WTest4;
		j wtest4
#begW4://                   {
begw4:
#                              //if (*hopPtr2 >= key)
 #                             if (*hopPtr2 < key) goto elseI5;
 		slt $t0, $t6, $t4
 		bgtz $t0, elsei5

#begI5://                      {
begi5:
#                                 hopPtr21 = endPtr2;
		move $t8, $a2
#				//while (hopPtr21 > hopPtr2)
		
#                                 goto WTest5;
		j wtest5
#begW5://   {
begw5:                      
#                                    *hopPtr21 = *(hopPtr21 - 1);
		addi $t8, $t8, -4
#                                    --hopPtr21;
		addi $t8, $t8, -4
#WTest5://    }
wtest5:                    
#                                 if (hopPtr21 > hopPtr2) goto begW5;
		slt $t0, $t6, $t8
		blez $t0, begw5
		
		
#
#                                 ///break;
#                                 goto brk2;
		j brk2
#                           ///goto endI5; // unreacheable
#//                            }
#elseI5://                      else
elsei5:
#//                            {
#                                 ++hopPtr2;
		addi $t6, $t6, 4
#endI5://                      }
endi5:
#WTest4://                  }
wtest4:
#                           if (hopPtr2 < endPtr2) goto begW4;
		slt $t0, $t6, $a2
		bgtz $t0, begw4
		
#brk2:
brk2:
#                           *hopPtr2 = key;
		move $t6, $t4
#                           ++size2;
		addi $t2, $t2, 4
#endI3://                }
endi3:
#                        avg = sum/size1;
		divu $t8, $t9, $t1
		mflo $t8
		
#                     ++hopPtr1;
		addi $t5, $t5, 4
#FTest1://            }
ftest1:
#                     if (hopPtr1 < endPtr1) goto begF1;
		slt $t0, $t5, $a1
		blez $t0, begf1 
#
#                     cout << begA1Str;
		li $v0, 4
		la $a0, begA1Str
		syscall
#                     //if (size1 > 0)
 #                    if (size1 <= 0) goto endI6;
 		li $s0, 0
 		slt $t0, $t1, $s0
		bltz $t0, endi6
		beq $t1, $s0, endi6

#begI6://             {
begi6:
#                        hopPtr1 = a1;
		la $t5, a1
#                        endPtr1 = a1 + size1;
 		la $a1, a1
 		sll $t0, $t1, 2
		add $a1, $a1, $t0
#//                      do
#begDW1://               {
begdw1:
 #                          cout << *hopPtr1 << ' ' << ' ';
 		li $v0, 1
		lw $a0, 0($t5) 
   		syscall
 		li $v0, 11
 		li $a0, ' '
 		syscall      
 		li $a0, ' '
 		syscall                                                                    #how do i print a pointer
 #                          ++hopPtr1;
 		addi $t5, $t5, 4
#DWTest1://              }
dwtest1:
 #                       //while (hopPtr1 < endPtr1);
#                        if (hopPtr1 < endPtr1) goto begDW1;
		slt $t0, $t5, $a1
		blez $t0, begdw1
#endI6://             }
endi6:
 #                    cout << endl;
  		li $v0, 11
 		li $a0, '\n'
 		syscall
#
 #                    cout << commA2Str;
  		li $v0, 4
 		la $a0, commA2Str
 		syscall
 #                    //if (size2 > 0)
 #                    if (size2 <= 0) goto endI7;
  		li $s0, 0
 		slt $t0, $t2, $s0
		bltz $t0, endi7
		beq $t2, $s0, endi7
#begI7://             {
begi7:
#                        hopPtr2 = a2;
		la $t6, a2
#                        endPtr2 = a2 + size2;
 		la $a2, a2
 		sll $t0, $t2, 2
		add $a2, $a2, $t0
#//                      do
#begDW2://               {
begdw2:
#                           cout << *hopPtr2 << ' ' << ' ';
 		li $v0, 1
		lw $a0, 0($t6) 
   		syscall
 		li $v0, 11
 		li $a0, ' '
 		syscall      
 		li $a0, ' '
 		syscall  
#                           ++hopPtr2;
		addi $t6, $t6, 4
#DWTest2://              }
dwtest2:
#                        //while (hopPtr2 < endPtr2);
 #                       if (hopPtr2 < endPtr2) goto begDW2;
 		slt $t0, $t6, $a2
		blez $t0, begdw2
#endI7://             }
endi7:
#                     cout << endl;
  		li $v0, 11
 		li $a0, '\n'
 		syscall
#
 #                    cout << commA3Str;
   		li $v0, 4
 		la $a0, commA3Str
 		syscall
#                     //if (size3 > 0)
#                     if (size3 <= 0) goto endI8;
  		li $s0, 0
 		slt $t0, $t3, $s0
		bltz $t0, endi8
		beq $t3, $s0, endi8
#begI8://             {
begi8:
 #                       hopPtr3 = a3;
 		la $t7, a3

 #                       endPtr3 = a3 + size3;
 		la $a3, a3
 		sll $t0, $t3, 2
		add $a3, $a3, $t0
#//                      do
#begDW3://               {
begdw3:
#                           cout << *hopPtr3 << ' ' << ' ';
 		li $v0, 1
		lw $a0, 0($t7) 
   		syscall
 		li $v0, 11
 		li $a0, ' '
 		syscall      
 		li $a0, ' '
 		syscall  
 #                          ++hopPtr3;
 		addi $t7, $t7, 4
#DWTest3://              }
dwtest3:
#                        //while (hopPtr3 < endPtr3);
#                        if (hopPtr3 < endPtr3) goto begDW3;
		slt $t0, $t7, $a3
		blez $t0, begdw3
#endI8://             }
endi8:
#                     cout << endl;
  		li $v0, 11
 		li $a0, '\n'
 		syscall
#
#                     hopPtr1 = a1;
		la $t5, a1
#                     hopPtr2 = a2;
		la $t6, a1
#                     hopPtr3 = a3;
		la $t7, a1
#                     endPtr2 = a2 + size2;
		
		la $a2, a2
		sll $t0, $t2, 2
		add $a2, $a2, $t0
 #                    endPtr3 = a3 + size3;
 		la $a3, a2
 		sll $t0, $t2, 2
		add $a3, $a3, $t0
#                     //while (hopPtr2 < endPtr2 && hopPtr3 < endPtr3)
 #                    goto WTest6;
 		j wtest6
#begW6://             {
begw6:

 #                       //if (*hopPtr2 < *hopPtr3)
 #                       if (*hopPtr2 >= *hopPtr3) goto elseI9;
 		slt $t0, $t7, $t6
		bgez $t0, elsei9
		beq $t6, $t7, elsei9
 		
#begI9://                {
begi9:
#                           *hopPtr1 = *hopPtr2;
		move $t5, $t6
#                           ++hopPtr2;
		addi $t6, $t6, 4
#                        goto endI9;
		j endi9
#//                      }
#elseI9://                else
elsei9:
#//                      {
#                           *hopPtr1 = *hopPtr3;
		move $t5, $t7
#                           ++hopPtr3;
#endI9://                }
endi9:
#                        ++hopPtr1;
		addi $t5, $t5, 4
#WTest6://            }
wtest6:
#                     ////if (hopPtr2 < endPtr2 && hopPtr3 < endPtr3) goto begW6;
#                     if (hopPtr2 >= endPtr2) goto xitW6;
 		slt $t0, $a2, $t6
		bgez $t0, xitw6
		beq $t6, $a2, xitw6
#                     if (hopPtr3 < endPtr3) goto begW6;
		slt $t0, $t7, $a3
		blez $t0, begw6
#xitW6:
xitw6:
#                     //while (hopPtr2 < endPtr2)
#                     goto WTest7;
		j wtest7
#begW7://             {
begw7:
#                        *hopPtr1 = *hopPtr2;
		move $t5, $t6
#                        ++hopPtr2;
		addi $t6, $t6, 4
#                        ++hopPtr1;
		addi $t5, $t5, 4
#WTest7://            }
wtest7:
#                     if (hopPtr2 < endPtr2) goto begW7;
		slt $t0, $t6, $a3
		blez $t0, begw7
#
#                     //while (hopPtr3 < endPtr3)
#                     goto WTest8;
		j wtest8
#begW8://             {
begw8:

#                        *hopPtr1 = *hopPtr3;
		move $t5, $t7
 #                       ++hopPtr3;
 		addi $t7, $t7, 4
 #                       ++hopPtr1;
  		addi $t5, $t5, 4
#WTest8://            }
wtest8:
#                     if (hopPtr3 < endPtr3) goto begW8;
		slt $t0, $t7, $a3
		blez $t0, begw8
#
#                     hopPtr2 = a2;
		la $t6, a2
 #                    hopPtr3 = a3;
 		la $t7, a3
 #                    size2 = 0;
 		li $t2, 0
 #                    size3 = 0;
 		li $t3, 0
 #                    //for (hopPtr1 = a1, endPtr1 = a1 + size1; hopPtr1 < endPtr1; ++hopPtr1)
 #                    hopPtr1 = a1;
 		la $t5, a1
 #                    endPtr1 = a1 + size1;
 		la $a1, a1
		sll $t0, $t1, 2
		add $a1, $a1, $t0
 #                    goto FTest2;
 		j ftest2
#begF2://             {
begf2:
#                        key = *hopPtr1;
		move $t4, $t5
#                        //if (key < avg)
#                        if (key >= avg) goto elseI10;
 		slt $t0, $t8, $t4
		bgez $t0, elsei10
		beq $t8, $t4, elsei10
#begI10://     {
begi10:          
#                           *hopPtr2 = key;
		move $t6, $t4
#                           ++size2;
		addi $t2, $t2, 4
 #                          ++hopPtr2;
 		addi $t6, $t6, 4
#                        goto endI10;
		j endi10
#//                      }
#elseI10://               else
elsei10:
#//                      {
#                           //if (key > avg)
#                           if (key <= avg) goto endI11;

		slt $t0, $t4, $t8
		bltz $t0, elsei4
		beq $t4, $t8, elsei4
#begI11://                  {
begi11:
#                              *hopPtr3 = key;
		move $t3, $t4
 #                             ++size3;
 		addi $t3, $t3, 4
#                              ++hopPtr3;
		addi $t7, $t7, 4
#endI11://                  }
endi11:
#endI10://               }
endi10:
 #                    ++hopPtr1;
 		addi $t7, $t7, 4
#FTest2://            }
ftest2:
 #                    if (hopPtr1 < endPtr1) goto begF2;
 		slt $t0, $t5, $a1
		blez $t0, begf2
#
 #                    cout << procA1Str;
 		li $v0, 4
 		la $a0, procA1Str
 		syscall
 #                    //if (size1 > 0)
 #                    if (size1 <= 0) goto endI12;
   		li $s0, 0
 		slt $t0, $t1, $s0
		bltz $t0, endi12
		beq $t1, $s0, endi12
#begI12://            {
begi12:
 #                       hopPtr1 = a1;
 		la $t5, a1
 #                       endPtr1 = a1 + size1;
		la $a1, a1
		sll $t0, $t1, 2
		add $a1, $a1, $t0
 #                       //do
#begDW4://               {
begdw4:
#                           cout << *hopPtr1 << ' ' << ' ';
 		li $v0, 1
		lw $a0, 0($t5) 
   		syscall
 		li $v0, 11
 		li $a0, ' '
 		syscall      
 		li $a0, ' '
 		syscall  
#                           ++hopPtr1;
 		addi $t5, $t5, 4
#DWTest4://               }
dwtest4:
 #                       //while (hopPtr1 < endPtr1);
 #                       if (hopPtr1 < endPtr1) goto begDW4;
  		slt $t0, $t5, $a1
		blez $t0, begdw4
#endI12://            }
endi12:
#                     cout << endl;
 		li $v0, 11
 		li $a0, '\n'
 		syscall 
#
 #                    cout << commA2Str;
  		li $v0, 4
 		la $a0, commA2Str
 		syscall 
 #                    //if (size2 > 0)
 #                    if (size2 <= 0) goto endI13;
    		li $s0, 0
 		slt $t0, $t2, $s0
		bltz $t0, endi13
		beq $t2, $s0, endi13
#begI13://            {
begi13:
 #                       hopPtr2 = a2;
 		la $t6, a2
 #                       endPtr2 = a2 + size2;
 		la $a2, a2
		sll $t0, $t2, 2
		add $a2, $a2, $t0
 #                       //do
#begDW5://               {
begdw5:
 #                          cout << *hopPtr2 << ' ' << ' ';
  		li $v0, 1
		lw $a0, 0($t6) 
   		syscall
 		li $v0, 11
 		li $a0, ' '
 		syscall      
 		li $a0, ' '
 		syscall  
 #                          ++hopPtr2;
 		addi $t6, $t6, 4
#DWTest5://               }
dwtest5:
 #                       //while (hopPtr2 < endPtr2);
 #                       if (hopPtr2 < endPtr2) goto begDW5;
   		slt $t0, $t6, $a2
		blez $t0, begdw5
#endI13://            }
endi13:
 #                    cout << endl;
  		li $v0, 11
 		li $a0, '\n'
 		syscall 
#
 #                    cout << commA3Str;
   		li $v0, 4
 		la $a0, commA3Str
 		syscall 
 #                    //if (size3 > 0)
 #                    if (size3 <= 0) goto endI14;
     		li $s0, 0
 		slt $t0, $t3, $s0
		bltz $t0, endi14
		beq $t3, $s0, endi14
#begI14://            {
begi14:
 #                       hopPtr3 = a3;
 		la $t7, a3
 #                       endPtr3 = a3 + size3;
  		la $a3, a3
		sll $t0, $t3, 2
		add $a3, $a3, $t0
 #                       //do
#begDW6://               {
begdw6:
#                           cout << *hopPtr3 << ' ' << ' ';
  		li $v0, 1
		lw $a0, 0($t6) 
   		syscall
 		li $v0, 11
 		li $a0, ' '
 		syscall      
 		li $a0, ' '
 		syscall  
#                           ++hopPtr3;
		addi $t7, $t7, 4
#DWTest6://               }
dwtest6:
 #                       //while (hopPtr3 < endPtr3);
 #                       if (hopPtr3 < endPtr3) goto begDW6;
    		slt $t0, $t7, $a3
		blez $t0, begdw6
#endI14://            }
endi14:
#                     cout << endl;
 		li $v0, 11
 		li $a0, '\n'
 		syscall
#endI2://          }
endi2:

 #                 cout << endl;
 		li $v0, 11
 		li $a0, '\n'
 		syscall
 		
 #                 cout << dacStr;
 		li $v0, 4
 		la $a0, dacStr
 		syscall
 #                 cin >> input;
 		li $v0, 12
		syscall
		sw $v0, 0($v1)
 #                 cout << endl;
 		li $v0, 11
 		li $a0, '\n'
 		syscall
#WTest1://      }
w1test:		
 #              ////if (input != 'n' && input != 'N') goto begW1;
 #              if (input == 'n') goto xitW1;
 #              if (input != 'N') goto begW1;
		li $t0, 'n'
		beq $v1, $t0, xitw1
		li $t0, 'N'
		bne $v1, $t0, begw1

#xitW1:]
xitw1:

 #              cout << dlStr << '\n';
 		li $v0, 4
 		la $a0, dlStr
 		syscall
 		li $v0, 11
 		li $a0, '\n'
 		syscall
 #              cout << byeStr << '\n';
 		li $v0, 4
 		la $a0, byeStr
 		syscall
  		li $v0, 11
 		li $a0, '\n'
 		syscall
 #              cout << dlStr << '\n';
 		li $v0, 4
 		la $a0, dlStr
 		syscall
  		li $v0, 11
 		li $a0, '\n'
 		syscall
#
 #              return 0;
#}

