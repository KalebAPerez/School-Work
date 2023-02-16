
/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
//entities first then collections
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "book.h"
#include "CD.h"
#include "DVD.h"
using namespace std;


vector<LibraryItem*> book::getvec(){
	return allBooks;
}


void book::lostbook(int hi){
	for (int i =0; i<allBooks.size();i++){
		if (allBooks.at(i)->getidnum() == hi){
			allBooks.at(i)->setstatus("lost");
		}
	}
}

void book::searchBook(){ //enter name and return id
	int temp;
	cout << "Please enter the library item ID" << endl;
	cin >> temp;
	
	for (int i =0; i<allBooks.size();i++){
		if (allBooks.at(i)->getidnum() == temp){
			allBooks[i]->printBook();
		}
	
	
}
}
void book::bookcheckin(int temp){
	
	for (int i =0; i<allBooks.size();i++){
		if (allBooks.at(i)->getidnum() == temp){
			allBooks.at(i)->setstatus("in");
			
			
			
		}
		
	}
	
	
}

bool book::bookin(int tempIS1){

	for (int i=0; i<allBooks.size();i++){
		if (allBooks.at(i)->getidnum() == tempIS1)
		{
			if (allBooks.at(i)->getstatus() == "out" || allBooks.at(i)->getstatus() == "lost" || allBooks.at(i)->getstatus() == "repair")
			{
				cout << "book is not available to be checked" <<endl;
				return 0;
			}
			else{
			allBooks.at(i)->setstatus("out"); 
			return 1;
			}
		}
	}
	
}

void book::addBook(){
LibraryItem* currentBook;
int tempidnum;
float tempcost;
string tempstatus;
int temploanperiod;
string tempAuthor;
string tempTitle;
int tempIsbn;
int tempId;
int tempCost;
string tempStatus;
string choice;

cout << "are you adding a book,cd or, dvd? (type in alll lowercase.)" << endl;
cin >> choice;

cout << "Enter ID num" << endl;
cin >> tempidnum;
cout << "Enter cost" << endl;
cin >> tempcost;
cout << "Enter status" << endl;
cin >> tempstatus;
cout << "Enter loan period" << endl;
cin >> temploanperiod;

if (choice == "book"){

cout << "Please enter book author:" << endl;
cin >> tempAuthor;
cin.ignore();
cout << "Please enter the title" << endl;
cin >> tempTitle;
cin.ignore();
cout << "Please enter the isbn" << endl;
cin >> tempIsbn;
cin.ignore();
cout << "Please enter the id" << endl;
cin >> tempId;
cin.ignore();
cout << "Please enter the cost" << endl;
cin >> tempCost;
cin.ignore();
cout << "Please enter the book's status" << endl;
cin >> tempStatus;
cin.ignore();
currentBook =  new EntityBook(tempidnum, tempcost, tempstatus, temploanperiod, tempAuthor, tempTitle, tempIsbn, tempId, tempCost, tempStatus);
allBooks.push_back(currentBook);
//storeBook();///////////////////////////////////////
}
else if (choice == "cd"){
	string tartist;
	string ttitle;
	int ttracks;
	int treleasedate;
	string tgenre;
	
	cout << "Please enter artist" << endl;
	cin >> tartist;
	cout << "Please enter title" << endl;
	cin >> ttitle;
	cout << "Please enter tracks" << endl;
	cin >> ttracks;
	cout << "please enter release" << endl;
	cin >> treleasedate;
	cout << "please enter genre" << endl;
	cin >> tgenre;
	
	currentBook = new CD(tempidnum, tempcost, tempstatus, temploanperiod, tartist, ttitle, ttracks, treleasedate, tgenre);
	allBooks.push_back(currentBook);
}
else if (choice == "dvd"){
	string temptit;
	string tcategory;
	float truntime;
	string tstudio;
	string treleasedate;
	
	cout << "Please enter title" << endl;
	cin >> temptit;
	cout << "Please enter category" << endl;
	cin >> tcategory;
	cout << "Please enter run time." << endl;
	cin >> truntime;
	cout << "Please enter studio" << endl;
	cin >> tstudio;
	cout << "Please enter release date" << endl;
	cin >> treleasedate;
	
	currentBook = new DVD(tempidnum, tempcost, tempstatus, temploanperiod, temptit, tcategory, truntime, tstudio, treleasedate);
	allBooks.push_back(currentBook);
}
}
void book::editBook(){
	LibraryItem* currentBook;
int tempidnum;
float tempcost;
string tempstatus;
int temploanperiod;
string tempAuthor;
string tempTitle;
int tempIsbn;
int tempId;
int tempCost;
string tempStatus;
	

	string choice;
	cout << "What is the ID of the item you would like to edit?" << endl;
	cin >> tempIsbn;
	cout << "Are you editing a book, cd, or dvd? (type in alll lowercase.)" << endl;
	cin >> choice;
	
cout << "Enter cost" << endl;
cin >> tempcost;
cout << "Enter status" << endl;
cin >> tempstatus;
cout << "Enter loan period" << endl;
cin >> temploanperiod;
	for (int i =0; i < allBooks.size(); i++)
	{
		if (allBooks.at(i)->getidnum() == tempIsbn && choice == "book")
		{
			
			




	cout << "Please enter book author:" << endl;
	cin >> tempAuthor;
	cin.ignore();
	cout << "Please enter the title" << endl;
	cin >> tempTitle;
	cin.ignore();
	cout << "Please enter the isbn" << endl;
	cin >> tempIsbn;
	cin.ignore();
	cout << "Please enter the id" << endl;
	cin >> tempId;
	cin.ignore();
	cout << "Please enter the cost" << endl;
	cin >> tempCost;
	cin.ignore();
	cout << "Please enter the book's status" << endl;
	cin >> tempStatus;
	cin.ignore();
	currentBook =  new EntityBook(tempidnum, tempcost, tempstatus, temploanperiod, tempAuthor, tempTitle, tempIsbn, tempId, tempCost, tempStatus);
	allBooks.at(i)=(currentBook);
	
		}
		
		else if (allBooks.at(i)->getidnum() == tempIsbn &&choice == "cd"){
	string tartist;
	string ttitle;
	int ttracks;
	int treleasedate;
	string tgenre;
	
	cout << "Please enter artist" << endl;
	cin >> tartist;
	cout << "Please enter title" << endl;
	cin >> ttitle;
	cout << "Please enter tracks" << endl;
	cin >> ttracks;
	cout << "please enter release" << endl;
	cin >> treleasedate;
	cout << "please enter genre" << endl;
	cin >> tgenre;
	
	currentBook = new CD(tempidnum, tempcost, tempstatus, temploanperiod, tartist, ttitle, ttracks, treleasedate, tgenre);
	allBooks.at(i)=(currentBook);
}
else if (allBooks.at(i)->getidnum() == tempIsbn &&choice == "dvd"){
	string temptit;
	string tcategory;
	float truntime;
	string tstudio;
	string treleasedate;
	
	cout << "Please enter title" << endl;
	cin >> temptit;
	cout << "Please enter category" << endl;
	cin >> tcategory;
	cout << "Please enter run time." << endl;
	cin >> truntime;
	cout << "Please enter studio" << endl;
	cin >> tstudio;
	cout << "Please enter release date" << endl;
	cin >> treleasedate;
	
	currentBook = new DVD(tempidnum, tempcost, tempstatus, temploanperiod, temptit, tcategory, truntime, tstudio, treleasedate);
	allBooks.at(i)=(currentBook);
}
	}
	
//storeBook();////////////////////////////////////
	
}

void book::printBook()
{
	for (int i =0; i < allBooks.size();i++)
	{
	allBooks[i]->printBook();	
	}
}

void book::loadBook(){

LibraryItem* currentBook;
string tempAuthor;
string tempTitle;
int tempIsbn;
int tempId;
int tempCost;
int size;
int ttype;
string tempStatus;
int tempidnum;
int tempcost;
string tempstatus;
int temploanperiod;

string artist;
string title;
int tracks;
int releasedate;
string genre;

string t0;
string t1;
float t2;
string t3;
string t4;
	ifstream file;
	file.open ("books.txt");
	file >> size;
	//file.ignore();
	for (int i = 0; i <size;i++)
	{
		file >> ttype ;
		if (ttype == 1){
			
		file>> tempidnum >> tempcost >> tempstatus >> temploanperiod >> tempAuthor >> tempTitle >> tempIsbn >> tempId >> tempCost >> tempStatus;
		
//	cout<< tempAuthor<< endl;
		currentBook =  new EntityBook(tempidnum, tempcost, tempstatus, temploanperiod, tempAuthor, tempTitle, tempIsbn, tempId, tempCost, tempStatus);
		allBooks.push_back(currentBook);
		}
		else if (ttype == 2 ){
		file >>  artist >> title >> tracks >> releasedate >> genre;
			currentBook = new CD(tempidnum, tempcost, tempstatus, temploanperiod, artist, title, tracks, releasedate, genre);
			allBooks.push_back(currentBook);
		}
		else if (ttype == 3){
			file >> tempidnum >> tempcost >> tempstatus >> temploanperiod >> t0 >> t1>> t2>>t3>>t4;
			currentBook = new DVD(tempidnum, tempcost, tempstatus, temploanperiod, t0, t1, t2, t3, t4);
			allBooks.push_back(currentBook);
			
		}

		itemcnt++;
	}
	file.close();
}
void book::storeBook(){
	ofstream file;
	file.open ("books.txt");
	file << allBooks.size() << endl;
	
	
	for (int i=0; i<allBooks.size();i++){
		cout <<"type: " <<((EntityBook*)allBooks[i])->gettype()<< endl;
		
		
	if (allBooks[i]->gettype() == 1) {
		
		file << ((EntityBook*)allBooks[i])->gettype() << " ";
		file << allBooks[i]->getidnum();
		file << allBooks[i]->getcost();
		file << allBooks[i]->getstatus();
		file << allBooks[i]->getloanperiod();
	
		

		file << ((EntityBook*)allBooks[i])->getauthor() << " ";
		file << ((EntityBook*)allBooks[i])->gettitle() << " ";
		file << ((EntityBook*)allBooks[i])->getisbn() << " ";
		file << ((EntityBook*)allBooks[i])->getid() << " ";
		file << ((EntityBook*)allBooks[i])->getcost() << " ";
		file << ((EntityBook*)allBooks[i])->getbookstat() << " " << endl;
	}
	else if (allBooks[i]->gettype() == 2){
				file << allBooks[i]->getidnum();
		file << allBooks[i]->getcost();
		file << allBooks[i]->getstatus();
		file << allBooks[i]->getloanperiod();
		file << ((CD*)allBooks[i])->gettype() << " ";
		file << ((CD*)allBooks[i])->getartist() << " ";
		file << ((CD*)allBooks[i])->gettracks() << " ";
		file << ((CD*)allBooks[i])->getreleasedate() << " ";
		file << ((CD*)allBooks[i])->getgenre() << " ";
		
		
		
	}
	else if (allBooks[i]->gettype() == 3){
				file << allBooks[i]->getidnum();
		file << allBooks[i]->getcost();
		file << allBooks[i]->getstatus();
		file << allBooks[i]->getloanperiod();
		file << ((DVD*)allBooks[i])->gettype() << " ";
		file << ((DVD*)allBooks[i])->getcategory() << " ";
		file << ((DVD*)allBooks[i])->getruntime() << " ";
		file << ((DVD*)allBooks[i])->getstudio() << " ";
		file << ((DVD*)allBooks[i])->getreleasedate() << " ";
		
	}
	

	}
	file.close();
}
void book::deleteBook()
{
	int tisbn;
	cout << "Enter Item ID" <<endl;
	cin >> tisbn;
	for (int i=0; i<allBooks.size();i++){
	if (allBooks.at(i)->getidnum() == tisbn)
	{
		allBooks.erase(allBooks.begin() + i);
	}
	}
	//storeBook();////////////////////
}
	
/*void book::printBookinfo(){
	int tisbn;
	
	cout << "Please enter an ID" <<endl;
	cin >> tisbn;
	for (int i=0; i<allBooks.size();i++){
		if (allBooks.at(i).getidnum() == tisbn)////////////////////////also fix print here
		{
			cout << allBooks[i].getauthor() << " ";
			cout << allBooks[i].gettitle() << " ";
			cout << allBooks[i].getisbn() << " ";
			cout << allBooks[i].getid() << " ";
			cout << allBooks[i].getcost() << " ";
			cout << allBooks[i].getbookstat() << " " << endl << endl;
		}
	}
	
}*/

	void book::printbyID(int o){
		
		
		for (int i=0; i<allBooks.size();i++){
		if (allBooks.at(i)->getidnum() == o)////////////////////////also fix print here
		{
			allBooks[i]->printBook();
		}
		}
	}
	
	int book :: getsize(){
		return allBooks.size();
	}
	
	
	
	
