/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include <string>
#include "EntityLoan.h"

void entityLoan::setallloan(int id1, int bid, int pid, int date, string stat) {
	loanid = id1;
	bookid = bid;
	patronid = pid;
	duedate = date;
	currentstatus = stat;
	
	
}
void entityLoan::setloanid(int id1) {loanid = id1;}
void entityLoan::setbookid(int bid) {bookid = bid;}
void entityLoan::setpatronid(int pid1) {patronid=pid1;}
void entityLoan::setduedate(int date1) {duedate = date1;}
void entityLoan::setcurrentstatus(string stat1) {currentstatus=stat1;}

int entityLoan::getloanid() {return loanid;}
int entityLoan::getbookid(){return bookid;}
int entityLoan::getpatronid(){return patronid;}
int entityLoan::getduedate(){return duedate;}
string entityLoan::getcurrentstatus(){return currentstatus;}