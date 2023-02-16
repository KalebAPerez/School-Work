/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include <string>
#include <iostream>
#include "LibraryItem.h"
using namespace std;

class EntityBook: public LibraryItem
{
public:
EntityBook(int temp1, float temp2, string temp3, int temp4, string author1, string title1, 
int isbn1, int id1, int cost1, string bookStatus1);


void setBook(string author1, string title1, 
int isbn1, int id1, int cost1, string bookStatus1);


void setAuthor (string a);
void setTitle (string t);
void setIsbn (int i);
void setId (int id1);
void setCost (int c);
void setbookstat (string b);
void setcategory(string h);

string getauthor ();
string gettitle ();
int getisbn ();
int getid ();
int getcost ();
string getbookstat ();
string getcategory();

virtual void printBook();
	

void printinfo();

private:
string author;
string title;
int isbn;
int id;
int cost;
string bookStatus;
string category;
};