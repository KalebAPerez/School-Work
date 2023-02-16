#include"CD.h"

CD::CD(int temp1, float temp2, string temp3, int temp4, string t1, 
string t2, int t3, int t4, string t5):LibraryItem(temp1, temp2, temp3, temp4){
	artist = t1;
	title =t2;
	tracks = t3;
	releasedate = t4;
	genre = t5;
type = 2;}

void CD::setartist(string temp){
	artist = temp;
}

void CD::settitle(string temp){
	title = temp;
}
void CD::settracks(int temp){
tracks = temp;	
}
void CD::setreleasedate(int temp){
	releasedate = temp;
}
void CD::setgenre(string temp){
	genre = temp;
}
	
string CD::getartist(){
	return artist;
}
string CD::gettitle(){
	return title;
}
int CD::gettracks(){
	return tracks;
}
int CD::getreleasedate(){
	return releasedate;
}
string CD::getgenre(){
	return genre;
}
	
	
	void CD::printBook(){
			cout << idnum << endl << cost << endl <<status << endl << loanperiod << endl;
			cout << artist << endl << title << tracks << releasedate << endl<< genre << endl;
	}