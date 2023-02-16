#include "LibraryItem.h"

class DVD:public LibraryItem{
	public:
	
	DVD(int temp1, float temp2, string temp3, int temp4, string t1, string t2, float t3, string t4, string t5);
	void settitle(string temp);
	void setcategory(string temp);
	void setruntime(float temp);
	void setstudio(string temp);
	void setreleasedate(string temp);
	
	string gettitle();
	string getcategory();
	float getruntime();
	string getstudio();
	string getreleasedate();
    void printBook();
	
	private:
	string title;
	string category;
	float runtime;
	string studio;
	string releasedate;
	
	
	
};