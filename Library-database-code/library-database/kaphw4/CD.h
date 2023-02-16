
#include<string>
#include"LibraryItem.h"

class CD:public LibraryItem{
	public:
	
	CD(int temp1, float temp2, string temp3, int temp4, string t1, string t2, int t3, int t4, string t5);
	void setartist(string temp);
	void settitle(string temp);
	void settracks(int temp);
	void setreleasedate(int temp);
	void setgenre(string temp);

	string getartist();
	string gettitle();
	int gettracks();
	int getreleasedate();
	string getgenre();
	
	 void printBook();
	
	private:
	string artist;
	string title;
	int tracks;
	int releasedate;
	string genre;
	
};