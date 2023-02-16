/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <time.h>

#include "LibraryItem.h"
#include "book.h"
#include "patron.h"
#include "loan.h"
#include "CD.h"
#include "DVD.h"


using namespace std;
book books;
//LibraryItem books;
patron patrons;
loan loans;

    




int main ()
{
	
	
	books.loadBook();
	books.storeBook();
	patrons.loadPatron();
	patrons.storePatron();
	loans.loadloan();
	loans.storeloan();
int choice = -1;
do {
	cout << "please make a selection." << endl << "1 = Items" << endl << "2 = patrons" << endl<< "3 = loans" << endl << "0 = quit" << endl;
	
	cin >> choice;
	switch (choice)
	{
		case 1: 
		{
			do {
				cout << "1 = add item"<< endl;
				cout << "2 = edit item" << endl;
				cout << "3 = delete item" <<endl;
			//	cout << "4 = search item" <<endl;
				cout << "5 = print all items" << endl;
				//cout << "6 = print single item info" << endl;
				cout << "7 = back to previous menu" << endl;
				cin >> choice;
				switch(choice){
					case 1: {books.addBook();
					break;		
					}
					case 2: {books.editBook();
					break;	
					}
					case 3: {
						books.deleteBook();
						break;
					}
					case 4:{
						books.searchBook();
					}
					case 5: {books.printBook();
					break;}
					//case 6: {books.printBookinfo();
					//break;
						
					//}
					}
			}while (choice !=7);
			
			break;
		}
		case 2: 
		{
			do{
				cout << "1 = add patrons"<< endl;
				cout << "2 = edit patrons" << endl;
				cout << "3 = delete patrons" <<endl;
				cout << "4 = search patrons" <<endl;
				cout << "5 = print all patrons" << endl;
				cout << "6 = print single patron's info" << endl;
				cout << "7 = pay fines" <<endl;
				cout << "8 = back to previous menu" << endl;
				cin >> choice;
				switch(choice)
				{
					case 1: {
						patrons.addPatron();
						break;
					}
					case 2: {
						patrons.editPatron();
						break;
					}
					case 3: {
						patrons.deletePatron();
						break;
					}
					case 4: {
						patrons.searchpatron();
					}
					case 5: {
						patrons.printPatron();
						break;
					}
					case 6:{
						patrons.printPatroninfo();
						break;
					}
					case 7:{
						patrons.payfines();
					}
				}
			}while(choice !=8);
		};
		case 3:{
			do{
				cout << "1 = Check out item"<< endl;
				cout << "2 = Return item" << endl;
				cout << "3 = List all overdue items" <<endl;
				cout << "4 = List all items for particular patron" <<endl;
				cout << "5 = update a loan" << endl;
				cout << "6 = Recheck an item" << endl;
				
				cout << "7 = Report an item as lost" <<endl;
				cout << "8 = back to previous menu" << endl;
				cin >> choice;
				switch(choice){
					case 1:{
						loans.checkoutbook();
						break;
					}
					case 2:{
						loans.checkinbook();
						break;
					}
					case 3:{
						loans.listoverdue();
						break;
					}
					
					case 4:{
						loans.printbooks();
						break;
					}
					case 5:{
						loans.updateloan();
						break;
					}
					case 6:{
						loans.recheck();
						break;
					}
					case 7:{
						loans.reportlost();
						break;
						
					}
					
					
					
				
			};
			
		}while (choice != 8);
		break;
		}

		case 0: {
			
	patrons.storePatron(); //look at why this does not work
	books.storeBook();
	loans.storeloan();
			exit(EXIT_FAILURE);
		}
		default: cout<< "please reenter";
	};
	
//	default: { cout << "hi";}
	
} while (choice != 0);
	patrons.storePatron(); //look at why this does not work
	books.storeBook();
	loans.storeloan();
//add more store
return 0;
}