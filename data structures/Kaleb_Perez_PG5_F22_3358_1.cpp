// Author : Kaleb Perez
//
// Serial Number : 34
//
// Due Date : 10 - 31 22
// Programming Assignment Number 5
//
// Fall 2022 - CS 3358 - 1
//
// Instructor: Husain Gholoom.
//
// This program is to practice recursion

#include <iostream>
#include <time.h>
using namespace std;

void reverse(int tempArray[], int tempSize);
int power1(int lastNum, int power);
void squareTable(int firstNum, int integer);
void vertical(int secondNum, int k, int digits[]);
int ascending(int thirdNum);
void reverse(int fourthNum);
bool prime(int fifthNum, int divisor);

int main()
{

    cout << endl;
    srand(time(NULL));
    //this chunk finds array size
    int size = 0; //used to track users input
    cout << "*** Welcome to My APP ***" << endl
         << endl << "Enter The array size. ( Must be >= 5 and <= 20 ) -> ";
    cin >> size;
    cout << endl << endl;

    if(size < 5 || size > 20)
    {
        cout << endl <<  "Invalid arrays size. Size must >= 5 and <= 20. " << endl << endl << endl;
        cout << "Kaleb Perez - Programmer" << endl << "October 2022" << endl << endl;
        return 0;
    }
    int myArray[size];

    //this chunk populates and displays array
    int temp = 0; //used to generate random number
    cout << "The generated array is : ";
    for(int i = 0; i <= size -1; ++i) //took out the -1 here after size
    {
        temp = 20+rand()%((500+1)-20);
        myArray[i] = temp;
        cout << myArray[i] << " ";
    }
    cout << endl << endl;

    //this chunk displays the reversed array
    cout << "Reversed Array is : ";
    reverse(myArray, size - 1);
    cout << endl << endl;

    //this is the chunk for taking power
    
    cout << myArray[size - 1] << " raised to the 2nd power is: " 
         << power1(myArray[size - 1], 2) << endl << endl;

    //this chunk will make the table of squares
    cout << "N     N Squared" << endl;
    squareTable(myArray[0], 1);

    //this chunk will vertically display 2nd num
    cout << myArray[1] << " vertically" << endl << endl;
    int digits[3]; // this var is to store digits of num
    vertical(myArray[1], 3, digits);
    cout << endl;

    //this chunk will determine if 3rd num is ascending
    
    if(ascending(myArray[2]))
    {
        cout << myArray[2] << " is in increasing order " << endl << endl;
    }
    else
    {
        cout << myArray[2] << " is not in increasing order " << endl << endl;
    }

   //this chunk wil reverse 4th
    cout << "Reversed of " << myArray[3] << " is " ;
    reverse(myArray[3]); 
    cout << endl << endl;

    //this chunk will determine prime

    cout << myArray[4];
     if( prime( myArray[size- 1], 2 )  )
    {
        cout << " is Prime: " << endl << endl;
    }
        
    else
    {
         cout << " is not Prime: " << endl << endl;
    }
       

    cout << "Kaleb Perez - Programmer" 
         << endl << "October 2022" << endl << endl;

    cout << endl << endl;

    return 0;
}

// this function will determine if a num is prime
bool prime(int fifthNum, int divisor)
{
    if( fifthNum <= 2 )
    {
         return ( fifthNum == 2 ) ? true : false;
    }
       
    if( fifthNum % divisor == 0 )
    {
        return false;
    }
  
    if( divisor * divisor > fifthNum )
    {
        return true;
    }
        
    return prime( fifthNum, divisor + 1 );
}
//this function will reverse a number
void reverse(int fourthNum)
{
    
    if(fourthNum < 10)
    {
        cout << fourthNum;
        return;
    }
    else
    {
        cout << fourthNum % 10;
        reverse(fourthNum/10);
    }
}


//function will display reverse aray
void reverse(int tempArray[], int tempSize)
{
    if(tempSize <= -1)
    {
         return;
    }
    cout << tempArray[tempSize] << " ";
    reverse(tempArray, tempSize -1);
}

//this is function for taking power
int power1(int lastNum, int power)
{
    int powerTemp = 0;
    if(power == 0)
    {
        powerTemp =1;
        return powerTemp;
    }
    else if (power == 1)
    {
        powerTemp = lastNum;
        return powerTemp;
    }
    else
    {
        powerTemp = (lastNum * power1(lastNum, power -1));
        return powerTemp;
    }
    

}

//this function will make the square table
void squareTable(int firstNum, int integer)
{
    if(integer > firstNum)
    {
        cout << endl;
        return;
    }

    cout <<integer << "     " << integer*integer << endl;
    squareTable(firstNum, integer + 1);
}

//this function displays vertical num
void vertical(int secondNum, int k, int digits[])
{

    if(k < 1)
    {
        return;
    }


    digits[k] = secondNum % 10;
    secondNum = secondNum / 10;
    vertical(secondNum, k - 1, digits);
    
    cout << digits[k] << endl;
}

//this function will determine if third number is ascending
int ascending(int thirdNum)
{
    int remainder = thirdNum % 10;
    int quotient = thirdNum / 10;

    if(remainder == thirdNum)
        return 1;
    else if (remainder <= (quotient % 10))
        return 0;
    else
        return 1 && ascending(quotient);
}

