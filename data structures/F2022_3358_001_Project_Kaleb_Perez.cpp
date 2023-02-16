// Author : Kaleb Perez
//
// Due Date : 11/28/22
//
// Programming Assignment Number 7
//
// Fall 2022 - CS 3358 - Your Section Number
//
// Instructor: Husain Gholoom.
//
// This program is practice building a hash table

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class hTable{

    private:
    int hash_pos;
    string myArray[27];

    public:

    hTable();
    int insert(string data);
    void search(string data);
    int Hash(string );
    int reHash(int );
    void Delete(string data);
    void Display();
};


int main()
{
    hTable h; //object oh hash
    ifstream myFile; //file object
    myFile.open("Word.txt");
    string myStr; //holds string from .txt

    if ( myFile.is_open() )
    {
        while(!myFile.eof())
        {
            getline(myFile, myStr);

            h.insert(myStr);
            myStr.clear();
        }
    }

    cout << "Hashing Program" << endl
    << endl << endl
    << "----------" << endl << endl
    <<"A. Creates a string array of size 27. Assigning - to each" << endl
    << "location in the array indicating that the array is empty." << endl
    <<"B. Populates 26 elements of the array with words" <<endl
    << "C. If a collision occurs, linear probing will find the next" <<endl
    << " available position / location" << endl
    << "D. The generated array will be displayed in 7 lines" << endl
    << "Each line contains 4 words separated by a tab spaces." << endl << endl;

    cout << "The generated array: " <<endl <<endl;

    h.Display();
    cout << endl << endl << endl << endl;
    cout << "Searching for a word ( Zulu) in the table. " << endl;
    h.search("Zulu");
    cout << endl << endl << endl;
    cout << "Searching for a word ( Hulu) in the table. " << endl;
    h.search("Hulu");
    cout << endl << endl;

    cout << endl << "Inserting a New word ( Mayday ) in the table " << endl;
    

   
    cout << "The word ( Mayday ) is inserted in location "
         << h.insert("Mayday") << endl <<endl << endl; 

    cout << "Inserting a New word (Bonanza) in the table."
         << endl;
    h.insert("Bonanza");
    cout << endl << endl << endl << endl;

    cout << "The Table After the words were inserted:" <<endl<<endl;
    h.Display();

    cout << endl << endl << endl;

    cout << "Delete the word (Zulu) form the table." << endl;
    h.Delete("Zulu");
    cout << endl << endl;
    cout << "Delete the word (Delta) form the table." << endl;
    h.Delete("Delta");

    cout << "Delete the word (Bonanza) form the table." << endl;
    h.Delete("Bonanza");

    cout << "Table after 2 word was deleted:" << endl;
    cout << endl;
    h.Display();

    cout << endl << "This hashing program was implemented by "
    << endl << "Kaleb Perez" << endl << "11 - 28 - 2022" << endl << endl;
}

//will delete a word from func
void hTable::Delete(string data)
{
    int probe = 0; //probe and collison counter
    int count2 = 0; //counts hashes
    int index = Hash(data); //index to be hashed
    bool isFound= false; //tracks if word is found
    while(myArray[index]!=data)
    {
        index = reHash(index);
        probe++;
        count2++;
        if(myArray[index]==data)
        {
            isFound= true;
        }
        if(count2 ==27)
        {
            break;
        }
    }
    if(isFound)
    {
    myArray[index] = '-';
    cout<<"The word " << data << " is deleted" << endl << endl;
    }
    else
    {
    cout<<"The word " << data << " is not found" <<endl << endl;
    }
    cout<<"The number of linear probes when each number is hashed and "
    << "collision occurred when deleting the"
    << endl << "word (" << data << " ) in the array is  " << probe << endl << endl;
}

//will set array to "-"
hTable::hTable()
{
    for(int i = 0; i < 27; i++)
    {
    myArray[i] = '-';
    }
}

//will insert a word to the hash
int hTable::insert(string position)
{
    int linProbe = 0; //collison and probe counter
    int count = 0; //iterator for insert

    hash_pos = Hash(position);


    while(myArray[hash_pos] != "-"){

        hash_pos = reHash(hash_pos);
        count++;
        if(hash_pos >= 27)
        {
            hash_pos = 0;
        }

        if(count >= 27)
        {
            cout << "The word (" << position << ") was not inserted. Table is Full" << endl;
            break;
        }
    }
    if(myArray[hash_pos] == "-"){
        myArray[hash_pos] = position;


    }
    return hash_pos;
}

//determines locations in hash
int hTable::Hash(string position)
{
    int key; //temp var for positio length
    key = position.length() % 27;
    return key;
}
//determines location for rehash
int hTable::reHash(int key){
    return (key+1)%27 ;
}

//displays hash
void hTable::Display()
{
int count3 = 0; //counts for newline

for(int i = 0; i < 27; i++)
{
    cout << myArray[i] << " ";
    count3++;
    if(count3 == 4)
    {
        cout << endl;
        count3 = 0;
    }
       
}
 cout << endl;
}

//searches for a word in hash
void hTable::search(string data){

    int probes = 0; //probe and collsion counter
    int count1 = 0; //iterator for search
    int index = Hash(data); //index to be hashed
    bool isFound = true; //tracks if found
    while(myArray[index] != data)
    {
        index = reHash(index);
        probes++;
        count1++;
        if(count1 == 27)
        {
            isFound = false;
            break;
        }
    }
    if(isFound)
    {
    cout << "The word (" << data << ") was found in location " << index
         << endl << endl
         << "The number of linear probes when each number is hashed"
         <<" and collision occurred when searching for the "
         << "word (" << data << ") in the array is " << probes;
    }
    if(!isFound)
    {
        cout << "The word (" << data << ") was not found in table." << endl << endl;
        cout << "The number of linear probes when each number is hashed"
         <<" and collision occurred when searching for the "
         << "word (" << data << ") in the array is " << probes;
    }

}

