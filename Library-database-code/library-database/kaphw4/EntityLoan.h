/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include <string>
#include <ctime>
using namespace std;

class entityLoan{

public:
void setallloan(int id1, int bid, int pid, int date, string stat);
void setloanid(int id1);
void setbookid(int bid1);
void setpatronid(int pid1);
void setduedate(int date1);
void setcurrentstatus(string stat1);

int getloanid();
int getbookid();
int getpatronid(); 
int getduedate();
string getcurrentstatus();

private:
int loanid;
int bookid;
int patronid;
int duedate;
string currentstatus;
};	

//creating loan promt for month day year standard hour