//
// Author : Kaleb Perez
//
// Serial Number : 34
//
// Programming Assignment Number 4
//
// Fall 2022 - CS 3358 - 1
//
// Due Date : 10-10-22
//
// Instructor: Husain Gholoom.
//
// Program is to practive with pointers
// and memory allocation
// to create different data structures.



#include <iostream>
#include <ctime>
using namespace std;

class node //contains linked list objects
{


public:
    int value;
    node* next = NULL;
};
//contains all of the functions for editing my queue
class queue 
{

    private:
    node* head = NULL;
    public:
    void addQ(int temp);
    void randomizeQ();
    void printQ();
    void insert500();
    void insert200();
    void removeFirst();
    void removeFourth();
    void findMin();
    void findMax();
    void deleteQ();
    void removeLast();
};
//removes last paramater
void queue::removeLast()
{

    if(head==NULL)
    {
        cout << "N. Removing the last element from "<<
        "the queue : ERROR QUEUE IS EMPTY";
        return;
    }
    //used to track current node in iteration
    node* current = head; 
    //used to track previous node in iteration
    node* previous = head;
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    previous->next=NULL;
    delete current;
    cout << "N. Removing the last element from the queue : ";


}
//deletes entire queue
void queue::deleteQ()
{
        
    node* current = new node();
    current = head;
    node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;

    cout << "M.Deleting the entire queue : Queue deleted";

}
//finds min in queue
void queue::findMin()
{
   int minimum = 999; //keeps track of lowest number
   node* temp = head;
   
    while (head != NULL) 
    {

        if (minimum > head->value)
        {
            minimum = head->value;
        }
        head = head->next;
    }

    cout << "I. Finding the Min element in the queue : "
     << minimum << endl;
    
   head = temp;
}
//finds max in queue
void queue::findMax()
{
    
    node* temp = head;
    int maximum = -999; //keeps track of highest number

    while (head != NULL) {
 

        if (maximum < head->value)
        {
            maximum = head->value;
        }
        head = head->next;
    }
    
    cout << "J. Finding the Max element in the queue : "
     << maximum << endl;
   head = temp;
}
//removes 4th spot in queue
void queue::removeFourth()
{
    node* temp = head;
    node* previous = head;
    for(int i = 0; i < 4; i++)
    {
        if(i == 4)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            if (i == 3)
            {
                previous->next = temp->next;
                delete temp;
            }
            else
            {
                previous = temp;           
                temp = temp->next; 
            }
        }
    }
   cout << "H. Removing the 4th"
   << " element from the queue : ";

}
//removes head of queue
void queue::removeFirst()
{
   node* temp = head;
   head = head->next;
   delete temp;
   cout << "G. Removing the first element" <<
   " from the queue ( FIFO ) : ";
}
//inserts -200 tp queue
void queue::insert200()
{
    node* temp = head->next;
    node* newNode = new node();
    newNode->value = -200;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "F. Inserting -200 in the"
    <<" 3rd location in the queue : ";
}
//inserts 500 into queue
void queue::insert500()
{
    node* current = head;
    node* previous = head;
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    node *newNode = new node;
    //Initialize newNode
    newNode->next = nullptr;
    newNode->value = -500;
    current->next= newNode;
    cout << "E. Inserting -500 in the queue ( FIFO ) : ";
}
//prints queue
void queue::printQ()
{  
    node* current = head;
    while(current != NULL)
    {
        cout << current -> value << " ";
        current = current->next;
    }
    cout << endl;
}
//adds 7 random elements
void queue::randomizeQ()
{
    
    for(int i = 0; i < 7; i++)
    {
    int temp = 0;
    temp = 105+rand()%((110+1)-105);
    this->addQ(temp);
    }
    cout << "B. Queue Elements: ";
}
//adds new node to queue
void queue::addQ(int temp)
{
    node*current = head;
    node *newNode = new node;
    //Initialize newNode
    newNode->next = nullptr;
    newNode->value = temp;

    if (current == NULL)
    {
       
        head = new node();
        head->value = temp;
        return;
    }

 
    while(current->next != NULL)
    {
        current = current->next;
       
    }
    current->next = newNode;
   
    return;

}



//holds all functions related to the stack
class stack
{

    private: 
    node* head = NULL;


    public:
    //node* head = NULL;
    void add(int temp);
    void pop();
    void randomize();
    void printStack();
    void addNeg20();
    void removeTopTwo();
    void deleteStack();
    void removeHead();

};
//removes head of stack
void stack::removeHead()
{

   if(head == NULL)
   {
        cout << "L. Removing the first element" <<
        " from the stack : ERROR STACK IS EMPTY";
        return;
   }
   node* temp = head;
   head = head->next;
   delete temp;
   cout << "L. Removing the first element from the stack :";

}
//deletes stack
void stack::deleteStack()
{
    
    node* current = new node();
    current = head;
    node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;

    cout << "K. Deleting the entire stack : Stack deleted.";
}
//removes top to parameters of stack
void stack::removeTopTwo()
{
    this->pop();
    this->pop();
    cout << "D. Removing the top two elements"
    <<" from the stack ( LIFO ) : ";
}
//adds -20 parameter
void stack::addNeg20()
{
    node* current = head;
    node* previous = head;
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    node *newNode = new node;
    //Initialize newNode
    newNode->next = nullptr;
    newNode->value = -20;
    current->next= newNode;
    cout << "C. Inserting -20 in the stack (LIFO): ";
}
//removes last parameter
void stack::pop()
{
    node* current = head;
    node* previous = head;
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    //cout << current->value;
    previous->next=NULL;
    delete current;
}
//prints my stack
void stack::printStack()
{
    node* current = head;
    while(current != NULL)
    {
        cout << current -> value << " ";
        current = current->next;
    }
cout << endl;
}

//adds random numbers to stack
void stack::randomize()
{
    
    for(int i = 0; i < 7; i++)
    {
    int temp = 0;
    temp = 60+rand()%((65+1)-60);
    this->add(temp);
    }
    cout << "A. Stack Elements: ";
}
//adds a number to stack
void stack::add(int temp)
{

    node*current = head;
    node *newNode = new node;
    //Initialize newNode
    newNode->next = nullptr;
    newNode->value = temp;

    if (current == NULL)
    {
       
        head = new node();
        head->value = temp;
        return;
    }

 
    while(current->next != NULL)
    {
        current = current->next;
       
    }
    current->next = newNode;
   
    return;
}




int main()
{
    cout << endl;
    // stores user choice to run code
    char userChoice = 'z'; 
    cout << "Linked List, Stack, Queue Operations" << endl;
    do
    {

        cout << endl;
        srand (time(NULL));
        stack mainStack; //create class instance
        queue mainQ; //create queue instance

        //these are all my function calls 
        mainStack.randomize();
        mainStack.printStack();
        mainQ.randomizeQ();
        mainQ.printQ();
        mainStack.addNeg20();
        mainStack.printStack();
        mainStack.removeTopTwo();
        mainStack.printStack();
        mainQ.insert500();
        mainQ.printQ();
        mainQ.insert200();
        mainQ.printQ();
        mainQ.removeFirst();
        mainQ.printQ();
        mainQ.removeFourth();
        mainQ.printQ();
        mainQ.findMin();
        mainQ.findMax();
        mainStack.deleteStack();
        mainStack.printStack();
        mainStack.removeHead();
        mainStack.printStack();
        mainQ.deleteQ();
        mainQ.printQ();
        mainQ.removeLast();
        mainQ.printQ();

        cout << endl;
        cout << "Enter X to terminate the program."
             << endl
             << "Enter anything else to re-execute"
             <<" the program ----- > ";
        cin >> userChoice;


    }
    while(userChoice != 'X');

    cout << endl;
    cout << "This LL / Stack & Queue"
    << " Program is Implemented By :" 
    << endl 
    <<"Kaleb Perez - October 10th , 2022";
    cout << endl;
    cout << endl;
    return 0;
    //exit gracefully
}
