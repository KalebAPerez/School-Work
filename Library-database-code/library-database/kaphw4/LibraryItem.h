#ifndef libitem
#define libitem
#include <string>
#include <iostream>
using namespace std;
class LibraryItem{
public:

LibraryItem();
LibraryItem(int temp1, float temp2, string temp3, int temp4);

void setlibitem(int temp1, float temp2, string temp3, int temp4);

void setIdnum(int temp);
void setcost(float temp);
void setstatus(string temp);
void setloanperiod(int temp);

int getidnum();
float getcost();
string getstatus();
int getloanperiod();
int gettype();

virtual void printBook(){
		cout << idnum << endl << cost << endl <<status << endl << loanperiod << endl;
}


protected:
int idnum;
float cost;
string status;
int loanperiod;

int type;

};
#endif