/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include <string>
#include <iostream>
#include <vector>

#include "EntityLoan.h"
//#include "book.h"
//#include "loan.h"
using namespace std;



class loan
{
public:
void checkoutbook();
void checkinbook();
void listoverdue();
void printbooks();
void updateloan();
void recheck();
void reportlost();
void loadloan();
void storeloan();

private:

vector<entityLoan> allLoans;
};