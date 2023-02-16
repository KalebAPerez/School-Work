#include"DVD.h"



DVD::DVD(int temp1, float temp2, string temp3, int temp4, string t1, string t2, 
float t3, string t4, string t5):LibraryItem(temp1, temp2, temp3, temp4){
	title =t1;
	category = t2;
	runtime = t3;
	studio = t4;
	releasedate = t5;
	type = 3;
}



void DVD::settitle(string temp){
	title = temp;
}
void DVD::setcategory(string temp){
	category = temp;
}
void DVD::setruntime(float temp){
	runtime=temp;
}
void DVD::setstudio(string temp){
	studio=temp;
}
void DVD::setreleasedate(string temp){
	releasedate=temp;
}
	
string DVD::gettitle(){
	return title;
}
string DVD::getcategory(){
	return category;
}
float DVD::getruntime(){
	return runtime;
}
string DVD::getstudio(){
	return studio;
}
string DVD::getreleasedate(){
	return releasedate;
}

	void DVD::printBook(){
		LibraryItem::printBook();
		cout << title << endl << category << endl << runtime << endl << studio << endl << releasedate << endl;
	}