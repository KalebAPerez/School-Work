/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include <string>
#include <iostream>
#include <vector>
#include "EntityBook.h"

using namespace std;
//complete search book
class book
{
public:
void addBook();
void editBook ();
void deleteBook();
void searchBook();
int getsize();
vector<LibraryItem*> getvec();

 void printBook();


//void printBookinfo();
void loadBook();
void storeBook();
bool bookin(int tempIS1);
void bookcheckin(int temp);
void printbyID(int o);
void lostbook(int hi);



private:
vector<LibraryItem*> allBooks;
int itemcnt;
};