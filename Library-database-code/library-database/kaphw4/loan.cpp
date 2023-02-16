/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/

#include<string>
#include<ctime>
#include<iostream>
#include<fstream>

#include "loan.h"
#include "patron.h"
#include "book.h"
//maybe list possible choices before making them make choice
extern book books;
extern patron patrons;

void loan::loadloan(){
entityLoan currentloan;
	string tempstat; 
	int tempId;
	int tempbookid;
	int temppatronid;
	int date;
	int size;
	
	ifstream file;
	file.open ("loans.txt");
	file >> size;
	//file.ignore();
	for (int i = 0; i <size;i++)
	{
		file >>  tempId >> tempbookid >> temppatronid >> date >> tempstat;
		//cout<< tempId<< endl;
		currentloan.setallloan(tempId, tempbookid, temppatronid, date, tempstat); 
		allLoans.push_back(currentloan);
		
	}
	file.close();
}

void loan::storeloan(){
	ofstream file;
	file.open ("loans.txt");
	file << allLoans.size() << endl;
	for (int i=0; i<allLoans.size();i++){
		file << allLoans[i].getloanid() << " ";
		file << allLoans[i].getbookid() << " ";
		file << allLoans[i].getpatronid() << " ";
		file << allLoans[i].getduedate() << " ";
		file << allLoans[i].getcurrentstatus() << " ";
		 
	}
	file.close();
}

void loan::reportlost(){
	int temp;
	int temp2;
	cout << "Please enter lost item's id." << endl;
	cin >> temp;
	cout << "please enter the patron's ID who checked the book." << endl;
	cin >> temp2;
		patrons.patroncheckin(temp2);
	
		books.lostbook(temp);
		
		for(int i = 0; i <books.getvec().size();i++){
			if(books.getvec().at(i)->getidnum() == temp){
				allLoans.erase(allLoans.begin() +i);//deletes loan
				
			}
		}
		
		/*for(int i = 0; i <allLoans.size();i++){
			if(allLoans.at(i).getbookid() == temp){
				allLoans.erase(allLoans.begin() +i);//deletes loan
				
			}
		}*/
	
	
}

void loan::recheck(){
	int temp;
	cout << "Please Enter loan ID" <<endl;
	cin >> temp;
	
	for(int i = 0; i <allLoans.size();i++){
		if (allLoans.at(i).getloanid() == temp){
			allLoans.at(i).setduedate(allLoans.at(i).getduedate() + 240);
			cout << "Book rechecked" << endl;
		}
		else {
			cout << "invalid ID" << endl;
		}
	}
	
}

void loan::updateloan(){
	entityLoan currentloan;
	int tempid, tempIS;
	int temploanid;
	string out= "out";
	
time_t rawtime = time(NULL);
struct tm *ptm = localtime(&rawtime);
int year = ptm->tm_year;
year = year * 24 *365;
int yday = ptm->tm_yday;
yday=yday*24;
int hour = ptm->tm_hour;
int totalHours=year+yday+hour+240;



//cout << totalHours;
	
	cout <<"Please enter patron's id";
	cin >> temploanid;

	if (!patrons.patroncheckout(tempid))
	{
		return;
	}

	cout << "Please enter book's ISBN";
	cin >> tempIS;
	if (!books.bookin(tempIS))
	{
		return;
	}
	cout << "Please enter loan ID." << endl;
	cin >> temploanid;
//throw info into a vector
//maybe undo if second case fails
currentloan.setallloan(temploanid, tempIS, tempid, totalHours, out);
allLoans.push_back(currentloan);
	
}

void loan::printbooks(){
	
	int temp;
	cout << "Please enter a patron ID" << endl;
	cin >> temp;
	
	
	
	for(int i = 0; i <allLoans.size();i++){
		if (allLoans.at(i).getpatronid() == temp){
			for (int j = 0; j < books.getsize(); i++)
				if(books.getvec().at(i)->getidnum() == allLoans.at(i).getbookid()){
			books.printbyID(allLoans.at(i).getbookid());
				}
		}
		
	}
	
}//search through loan for loans matching patrons id and print books

void loan::listoverdue(){
	
time_t rawtime = time(NULL);
struct tm *ptm = localtime(&rawtime);
int year = ptm->tm_year;
year = year * 24 *365;
int yday = ptm->tm_yday;
yday=yday*24;
int hour = ptm->tm_hour;
int totalHours=year+yday+hour;
	
	for (int i=0; i < allLoans.size();i++){
		if ( totalHours > allLoans.at(i).getduedate()){
			books.printbyID(allLoans.at(i).getbookid());
			
		}
		else{
			cout << "There are no books overdue" << endl;
		}
		
	}
	
}
void loan::checkinbook(){
	
	int temploan;
	int patid;
	int book;
	cout << "Please enter loan ID";
	cin >> temploan;
	int tfine;
	
	
	
time_t rawtime = time(NULL);
struct tm *ptm = localtime(&rawtime);
int year = ptm->tm_year;
year = year * 24 *365;
int yday = ptm->tm_yday;
yday=yday*24;
int hour = ptm->tm_hour;
int totalHours=year+yday+hour;

	
	for (int i=0; i < allLoans.size();i++){
		if (allLoans.at(i).getloanid() == temploan){//take book off patron
			patid = allLoans.at(i).getpatronid();
			patrons.patroncheckin(patid);
			
		}
	
	}
	
	for (int i=0; i < allLoans.size();i++){
		if (allLoans.at(i).getloanid() == temploan){//returns the book
			book = allLoans.at(i).getbookid();
			books.bookcheckin(book);
			
			
		}
	
	}
	
	for (int i= 0; i<allLoans.size();i++){
		if (allLoans.at(i).getloanid() == temploan){
			if ( totalHours > allLoans.at(i).getduedate()){//checks for fines
				int finedays = (totalHours-allLoans.at(i).getduedate()) /24 ;
				cout << "You have " << finedays* .25<< " in fines"<< endl;
			}
		}
		
		
	}
	for (int i= 0; i<allLoans.size();i++){
		if (allLoans.at(i).getloanid() == temploan){
			allLoans.erase(allLoans.begin(), allLoans.begin() +i);//erases the loan vector
			
		}
		
		
	}
	
	
	
	//fines? is it past due
	//assign fines
	
	
}
void loan::checkoutbook(){
	
	entityLoan currentloan;
	int tempid, tempIS;
	int temploanid;
	string out= "out";
	
time_t rawtime = time(NULL);
struct tm *ptm = localtime(&rawtime);
int year = ptm->tm_year;
year = year * 24 *365;
int yday = ptm->tm_yday;
yday=yday*24;
int hour = ptm->tm_hour;
int totalHours=year+yday+hour+240;



//cout << totalHours;
	
	cout <<"Please enter patron's id";
	cin >> tempid;

	if (!patrons.patroncheckout(tempid))
	{
		return;
	}

	cout << "Please enter Item's ID";
	cin >> tempIS;
	if (!books.bookin(tempIS))
	{
		return;
	}
	cout << "Please enter loan ID." << endl;
	cin >> temploanid;
//throw info into a vector
//maybe undo if second case fails
currentloan.setallloan(temploanid, tempIS, tempid, totalHours, out);
allLoans.push_back(currentloan);
}