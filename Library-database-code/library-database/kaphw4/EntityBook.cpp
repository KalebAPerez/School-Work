/*D #
2. Cost
3.Status (In, out, lost)
4.Loan period(how long it can be checked out for-note this could be 0)
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include "book.h"



/*void EntityBook::printBook()
{
		
		cout << allBooks[i]->getauthor() << " ";
		cout << allBooks[i]->gettitle() << " ";
		cout << allBooks[i]->getisbn() << " ";
		cout << allBooks[i]->getid() << " ";
		cout << allBooks[i]->getcost() << " ";
		cout << allBooks[i]->getbookstat() << " " << endl;///////////////////////////somehow print other stuff
	
}*/

EntityBook::EntityBook(int temp1, float temp2, string temp3, int temp4,string author1, string title1, 
int isbn1, int id1, int cost1, string bookStatus1):LibraryItem(temp1, temp2, temp3, temp4){
	
author = author1;
title = title1;
isbn=isbn1;
id=id1;
cost=cost1;
bookStatus=bookStatus1;

type = 1;


}
void EntityBook::printBook(){
	LibraryItem::printBook();
	cout << author << endl<< title << endl << isbn << endl << id << endl << cost << endl << bookStatus << endl << category;
}

//#include "EntityBook.h"
void EntityBook::setBook(string author1, string title1, 
int isbn1, int id1, int cost1, string bookStatus1){
author = author1;
title = title1;
isbn=isbn1;
id=id1;
cost=cost1;
bookStatus=bookStatus1;
}


void EntityBook::setAuthor(string  a) {author = a;}
void EntityBook::setTitle(string  t) {title = t;}
void EntityBook::setIsbn(int i) {isbn = i;}
void EntityBook::setId(int id1) {id = id1;}
void EntityBook::setCost(int c) {cost = c;}
void EntityBook::setbookstat(string  b) {bookStatus = b;}
void EntityBook::setcategory(string h) {category = h;}

string EntityBook::getauthor() {return author;}
string EntityBook::gettitle() {return title;}
int EntityBook::getisbn() {return isbn;}
int EntityBook::getid() {return id;}
int EntityBook::getcost() {return cost;}
string EntityBook::getbookstat() {return bookStatus;}
string EntityBook::getcategory() {return category;}