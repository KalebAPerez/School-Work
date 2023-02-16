/*
Kaleb Perez
CSCE 1040
David Keathly
Homework 3
*/
#include <string>
using namespace std;

class entityPatron{
	
	public: 
	void setPatron(string name1, int pid1, int fines1, int booksout1);
	void setname(string name1);
	void setpid(int pid1);
	void setfines(int fine1);
	void setbooksout(int booksout1);
	
	string getpname();
	int getpfine();
	int getppid();
	int getbooksout();
	
	private:
string name;
int pid;
int fines;
int booksOut;
};