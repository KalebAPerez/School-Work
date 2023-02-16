/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include <string>
#include "EntityPatron.h"

void entityPatron::setPatron(string name1, int pid1, int fines1, int booksout1){
	name = name1;
	pid = pid1;
	fines = fines1;
	booksOut=booksout1;
	
}
void entityPatron::setname(string name1) {name = name1;}
void entityPatron::setpid(int pid1) {pid = pid1;}
void entityPatron::setfines(int fine1) {fines= fine1;}
void entityPatron::setbooksout(int booksout1) {booksOut = booksout1;}

string entityPatron::getpname(){return name;}
int entityPatron::getppid(){return pid;}
int entityPatron::getpfine(){return fines;}
int entityPatron::getbooksout(){return booksOut;}