
#include "LibraryItem.h"

LibraryItem::LibraryItem(int temp1, float temp2, string temp3, int temp4){
	idnum = temp1;
	cost = temp2;
	status= temp3;
	loanperiod = temp4;
}

void LibraryItem::setIdnum(int temp){
	idnum = temp;
}
void LibraryItem::setcost(float temp){
	cost = temp;
}
void LibraryItem::setstatus(string temp){
	status = temp;
}
void LibraryItem::setloanperiod(int temp){
	loanperiod = temp;
}

int LibraryItem::getidnum(){
	return idnum;
}
float LibraryItem::getcost(){
	return cost;
}
string LibraryItem::getstatus(){
	return status;
}
int LibraryItem::getloanperiod(){
	return loanperiod;
}

/*virtual void LibraryItem::printinfo(){
	cout << idnum << endl << cost << endl <<status << endl << loanperiod << endl;
}*/

LibraryItem::LibraryItem(){
	idnum = 0;
	cost = 0.0;
	status = " ";
	loanperiod = 0;
	
	
}

void LibraryItem::setlibitem(int temp1, float temp2, string temp3, int temp4){
	
	idnum = temp1;
	cost = temp2;
	status= temp3;
	loanperiod = temp4;
}

int LibraryItem::gettype(){
	return type;
	
}