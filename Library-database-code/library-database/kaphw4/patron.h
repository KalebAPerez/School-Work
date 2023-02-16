/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3 
*/
#include <string>
#include <iostream>
#include <vector>
#include "EntityPatron.h"
using namespace std;
//complete search patron and search book

class patron
{
public:
void addPatron();
void editPatron ();
void deletePatron();
void searchpatron();
void printPatron();
void printPatroninfo();
void loadPatron();
void storePatron();
bool patroncheckout(int tempid1);
void patroncheckin(int temp);
void payfines();

private:
int custcnt;
vector<entityPatron> allPatrons;
};