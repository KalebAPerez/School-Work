
/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include<string>
#include<vector>
#include<fstream>
#include "patron.h"


void patron::payfines(){
	int temp;
	float temp2;
	cout << "Please enter ID for patron to pay fines." << endl;
	cin >> temp;
	
	for (int i =0; i<allPatrons.size(); i++){
		if (allPatrons.at(i).getppid() == temp){
			cout << "How much was paid?" << endl;
			cin >>temp2;
			allPatrons.at(i).setfines(allPatrons.at(i).getpfine() - temp2);
			cout << "You have $" <<allPatrons.at(i).getpfine() << " left in fines." << endl;
		}
	}
	
	
	
}
void patron::searchpatron(){
	string temp;
	cout << "Please enter a patron name" << endl;
	cin >> temp;
	
	for (int i =0; i<allPatrons.size();i++){
		if (allPatrons.at(i).getpname() == temp){
			cout << allPatrons.at(i).getppid() << " is the ID you need" << endl << endl;
		}
	
	
}
}
void patron::patroncheckin(int temp){
	
	for (int i = 0; i < allPatrons.size(); i++){
		if (allPatrons.at(i).getppid()==temp){
			allPatrons.at(i).setbooksout(allPatrons.at(i).getbooksout()-1);
					
		}
		
		
	}
	
	
}

bool patron::patroncheckout(int tempid1){
	int tempid;

	for (int i=0; i<allPatrons.size();i++){
		if (allPatrons.at(i).getppid() == tempid1)
		{
			if (allPatrons.at(i).getbooksout() >= 6)
			{
				cout << "User has too many books checked" <<endl;
				return 0;
			}
			else{
				allPatrons.at(i).setbooksout(allPatrons.at(i).getbooksout() +1);
			return 1;
			}
		}
	}
	
}
void patron::addPatron(){
entityPatron currentPatron;
string tname;
int tid;
int tfines;
int tbooksout;

cout << "Please enter patron name:" << endl;
cin >> tname;
cin.ignore();
cout << "Please enter patron id" << endl;
cin >> tid;
cin.ignore();
cout << "Please enter total fines" << endl;
cin >> tfines;
cin.ignore();
cout << "Please enter total books out" << endl;
cin >> tbooksout;
cin.ignore();


//fix
currentPatron.setPatron(tname, tid, tfines, tbooksout); 
allPatrons.push_back(currentPatron);
storePatron(); 
}
void patron::editPatron(){
	int tempId;
	cout << "What is the ID of the profile you would like to find" << endl;
	cin >> tempId;
	for (int i =0; i < allPatrons.size(); i++)
	{
		if (allPatrons.at(i).getppid() == tempId)
		{
	entityPatron currentPatron;
	string tempname; 
	int tempId;
	int tempfines;
	int tempbooksout;

	cout << "Please enter name" << endl;
	cin >> tempname;
	cin.ignore();
	cout << "Please enter the Id" << endl;
	cin >> tempId;
	cin.ignore();
	cout << "Please enter the fines" << endl;
	cin >> tempfines;
	cin.ignore();
	cout << "Please enter the books out" << endl;
	cin >> tempbooksout;
	cin.ignore();
	
	currentPatron.setPatron(tempname, tempId, tempfines, tempbooksout);
	allPatrons.at(i) = currentPatron;
	
		}
	}
	
	storePatron();
	
}

void patron::loadPatron(){
entityPatron currentPatron;
	string tempname; 
	int tempId;
	int tempfines;
	int tempbooksout;
	int size;
	
	ifstream file;
	file.open ("patrons.txt");
	file >> size;
	file.ignore();
	for (int i = 0; i <size;i++)
	{
		file >>  tempname >> tempId >> tempfines >> tempbooksout;
		//cout<< tempname<< endl;
		currentPatron.setPatron(tempname, tempId, tempfines, tempbooksout); 
		allPatrons.push_back(currentPatron);
		
	}
	file.close();
}

void patron::storePatron(){
	ofstream file;
	file.open ("patrons.txt");
	file << allPatrons.size() << endl;
	for (int i=0; i<allPatrons.size();i++){
		file << allPatrons[i].getpname() << " ";
		file << allPatrons[i].getppid() << " ";
		file << allPatrons[i].getpfine() << " ";
		file << allPatrons[i].getbooksout() << " ";
		
		 
	}
	file.close();
}
void patron::deletePatron()
{
	int tid;
	cout << "Enter patron id" <<endl;
	cin >> tid;
	for (int i=0; i<allPatrons.size();i++){
	if (allPatrons.at(i).getppid() == tid)
	{
		allPatrons.erase(allPatrons.begin() + i);
	}
	} 
	storePatron();
}
void patron::printPatron()
{
	for (int i =0; i < allPatrons.size();i++)
	{
		cout << allPatrons[i].getpname() << " ";
		cout << allPatrons[i].getppid() << " ";
		cout << allPatrons[i].getpfine() << " ";
		cout << allPatrons[i].getbooksout() << " "<< endl;
		
	}
}
void patron::printPatroninfo(){
	int tid;
	
	cout << "Please enter an ID" <<endl;
	cin >> tid;
	for (int i=0; i<allPatrons.size();i++){
		if (allPatrons.at(i).getppid() == tid)
		{
			cout << allPatrons[i].getpname() << " ";
			cout << allPatrons[i].getppid() << " ";
			cout << allPatrons[i].getpfine() << " ";
			cout << allPatrons[i].getbooksout() << " ";
			
		}
	}
	
}

