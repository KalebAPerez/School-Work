// Author : Kaleb Perez
// Due Date : 11/9/22
// Programming Assignment Number 6
//
// Fall 2022 - CS 3358 - 1
//
// Instructor: Husain Gholoom.
//
// Function is to practice sorting and benchmarking

#include <time.h>
#include <iostream>
using namespace std;

void displayArray(int tempNum[],
 char tempChar[],int userTemp, int trigger);
void sortCharArray(char tempChar[],
 int userTemp, int &swapTemp);
void sortNumArray(int tempNum[],
 int userTemp, int &swapTemp);
void duplicateChar(char tempChar[],
 int userTemp, char copyArr[]);
void middleQuickSort(char tempChar[],
 int left, int right, int &swaps);
void duplicateInt(int tempNum[],
 int userTemp, int copyArr[]);
void middleQuickSortInt(int tempNum[],
 int left, int right, int &swaps);
void thirdValueSort(char tempChar[],
 int left, int right, int &swaps);
void thirdValueSortInt(int tempNum[],
 int left, int right, int &swaps);
int sequentalSearch(char tempChar[],
 int userNum, int &swaps);
int binarySearch(char tempChar[],
 int userNum, int &swaps);

int main()
{
    srand(time(NULL));
    cout << endl;
    //validating user input to be an int > 9
    int userNum = 0; //holds users number selection
    time_t start, //holds start and finish time for functions
           finish;
    cout << "Searching / Sorting Benchmark" 
    << endl << endl << endl;
   
    cout << "Enter the size of the array ( Must be > 9 ) : ";
    cin >> userNum;
    cout << endl;


    if(cin.fail() || userNum < 10)
    {
        cout << "*** Error - Invalid input - Size must be > 9 ***" 
        << endl << endl;
        cout << "November - 2022" << endl 
        <<"Sorting / Searching Benchmark by :"
        << endl << "Kaleb Perez";
        return 0;
    }
  
    char charArray[userNum]; //holds char array
    int numArray[userNum]; //holds num array

    //generates random data for arrays
    for(int i=0; i < userNum; i++)
    {
        charArray[i] = 97 + rand() % 26;
    }

    for(int i=0; i < userNum; i++)
    {
        numArray[i] = 1+rand()%((25+1)-1);
    }

    cout << "Character Array elements are : ";
    displayArray(numArray, charArray, userNum, 0);
   
    cout << "Integer Array elements are : ";
    displayArray(numArray, charArray, userNum, 1);
   
    double time; //holds time calculation
    int swaps = 0; //holds swaps in sort function
    char charArrayCopy[userNum];

    //this is the chunk for selection sort chars
    double selSortChar = 0;
    duplicateChar(charArray, userNum, charArrayCopy);
    start = clock();
    sortCharArray(charArrayCopy, userNum, swaps);
    finish = clock();
    time = double(finish - start);
    selSortChar = time;
    cout <<endl << "Character Array Selection Sort : " 
    << endl << endl
    << "Start Time     :   " << start 
    << endl
    << "End Time       :   " << finish
    << endl
    << "Actual CPU Clock time     :   " << time
    << endl
    << "Total Number of Swaps     : " << swaps
    << endl
    << "Sorted Elements: ";
    displayArray(numArray, charArrayCopy, userNum, 0);
    cout << endl;
    swaps = 0;

    int intArrayCopy[userNum]; //holds temp array for int
    //selection sort int array
    double intSelectionSortTime = 0;
    duplicateInt(numArray, userNum, intArrayCopy);
    start = clock();
    sortNumArray(intArrayCopy, userNum, swaps);
    finish = clock();
    time = double(finish - start);
    intSelectionSortTime = time;
    cout << "Integer Array Selection Sort : "  
    << endl << endl
    << "Start Time     :   " << start 
    << endl
    << "End Time       :   " << finish
    << endl
    << "Actual CPU Clock time     :   " << time
    << endl
    << "Total Number of Swaps     : " << swaps
    << endl
    << "Sorted Elements: ";
    displayArray(intArrayCopy, charArray, userNum, 1);
    cout << endl;
    swaps = 0;

    //middle quick sort char
    double middleSortTimeChar = 0;
    duplicateChar(charArray, userNum, charArrayCopy);
    start = clock();
    middleQuickSort(charArrayCopy, 0, userNum - 1, swaps);
    finish = clock();
    time = double(finish - start);
    middleSortTimeChar = time;
    cout << "Character Array Quick Sort -" <<
    " The Middle element as a pivot : "  
    << endl << endl
    << "Start Time     :   " << start 
    << endl
    << "End Time       :   " << finish
    << endl
    << "Actual CPU Clock time     :  " << time
    << endl
    << "Number of Recursive calls : " << swaps
    << endl
    << "Sorted Elements: ";
    displayArray(intArrayCopy, charArrayCopy, userNum, 0);
    cout << endl;
    swaps = 0;

    //middle quick sort int
    double quickSortInt = 0;
    duplicateInt(numArray, userNum, intArrayCopy);
    start = clock();
    middleQuickSortInt(intArrayCopy, 0, userNum - 1, swaps);
    finish = clock();
    time = double(finish - start);
    quickSortInt = time;
    cout << "Integer Array Quick Sort -" <<
    " The Middle element as a pivot : "  
    << endl << endl
    << "Start Time     :   " << start 
    << endl
    << "End Time       :   " << finish
    << endl
    << "Actual CPU Clock time     :  " << time
    << endl
    << "Number of Recursive calls : " << swaps
    << endl
    << "Sorted Elements: ";
    displayArray(intArrayCopy, charArrayCopy, userNum, 1);
    cout << endl;
    swaps = 0;

    //third num sort for chars
    double charSortThird = 0;
    duplicateChar(charArray, userNum, charArrayCopy);
    start = clock();
    thirdValueSort(charArrayCopy, 0, userNum - 1, swaps);
    finish = clock();
    time = double(finish - start);
    charSortThird = time;
    cout << "Character Array Quick Sort -" <<
    " The Third element as a pivot : "  
    << endl << endl
    << "Start Time     :   " << start 
    << endl
    << "End Time     :   " << finish
    << endl
    << "Actual CPU Clock time     :   " << time
    << endl
    << "Number of Recursive calls : " << swaps
    << endl
    << "Sorted Elements: ";
    displayArray(intArrayCopy, charArrayCopy, userNum, 0);
    cout << endl;
    swaps = 0;

    //quick sort 3rd spot int
    double intThirdSort = 0; //holds time for final output
    duplicateInt(numArray, userNum, intArrayCopy);
    time = clock();
    thirdValueSortInt(intArrayCopy, 0, userNum - 1, swaps);
    time = clock() - time;
    intThirdSort = time;
    cout << "Character Array Quick Sort -" 
    << " The Third element as a pivot : "  
    << endl << endl
    << "Start Time     :   " << start 
    << endl
    << "End Time     :   " << finish
    << endl
    << "Actual CPU Clock time     :   " << time
    << endl
    << "Number of Recursive calls : " << swaps
    << endl
    << "Sorted Elements: ";
    displayArray(intArrayCopy, charArrayCopy, userNum, 1);
    cout << endl;
    swaps = 0;

    //sequental search
    double seqSearchTime = 0;
    int trigger = 0;
    duplicateChar(charArray, userNum, charArrayCopy);
    start = clock();
    sequentalSearch(charArray, userNum, swaps);
    finish = clock();
    time = double(finish - start);
    seqSearchTime = time;
    cout << "Sequential Search " << endl
    << endl
    << "Searching for  Char P"
    << endl << endl;
    //determins if P was found
    if(trigger == 1)
    cout << "Char P Was found" << endl;

    if(trigger == 0)
    cout << "Char P Was Not Found" << endl;

    cout << "Start Time     :   " << start 
    << endl
    << "End Time     :   " << finish
    << endl
    << "Actual CPU Clock time     :   " << time
    << endl
    << "Total Number of Comparisons: " << swaps
    << endl << endl << endl;
    swaps = 0;

    //binary Search
    double binarySearchTime = 0; //holds final search time
    duplicateChar(charArray, userNum, charArrayCopy);
    start = clock();
    trigger = binarySearch(charArray, userNum, swaps);
    finish = clock();
    time = double(finish - start);
    binarySearchTime = time;
    cout << "Binary Search " << endl
    << endl
    << "Searching for  Char P"
    << endl << endl << endl;

    //determins if P was found
    if(trigger == 0)
    cout << "Char P Was Not Found" << endl;
    else
    cout << "Char P Was Found" << endl;
    cout << "Start Time     :   " << start 
    << endl
    << "End Time     :   " << finish
    << endl
    << "Actual CPU Clock time     :   " << time
    << endl
    << "Total Number of Comparisons: " << swaps
    << endl << endl;
    swaps = 0;

    //time summary char
    cout << "Actual CPU Time Summary:"
    << endl << endl
    << "Character Array Size: " << userNum
    <<endl << endl
    << "Selection Sort Time : " << selSortChar
    << endl
    << "Quick Sort Time - Middle Element as pivot: "
    << middleSortTimeChar
    << endl
    << "Quick Sort Time - Third Element as Pivot: "
    << charSortThird
    << endl << endl << endl << endl;

    //time summary int
    cout << "Integer Array Size: " << userNum
    <<endl << endl
    << "Selection Sort Time : "
    << intSelectionSortTime
    << endl
    << "Quick Sort Time - Middle Element as pivot: "
    << quickSortInt
    << endl
    << "Quick Sort Time - Third Element as Pivot: "
    << intThirdSort
    << endl << endl << endl << endl;

   

    //search times
    cout << "Searching for an Element not in the array: "
    << endl << endl
    << "Character Array Size : " 
    << userNum
    << endl << endl
    << "Sequential Search:   " 
    << " Actual CPU Clock time : " << seqSearchTime 
    << endl
    << "Binary Search :   " 
    << " Actual CPU Clock time : " << binarySearchTime
    << endl << endl << endl;

    cout << "End of Summary "
    << endl << endl;

    cout << "November - 2022" << endl <<"Sorting / Searching Benchmark by :"
    << endl << "Kaleb Perez" << endl;
    cout << endl;

    return 0;
}

//will display the two arrays
void displayArray(int tempNum[], 
char tempChar[], int userTemp, int trigger)
{

    if(trigger == 0)
    {
        
        for(int i=0; i < userTemp; i++)
        {
            if(i == 20)
            break;
            cout << tempChar[i] << " ";
        }
        cout << endl << endl;
    }
    else if(trigger ==1)
    {
    
        for(int i=0; i < userTemp; i++)
        {
            if(i == 20)
            break;
        cout << tempNum[i] << " ";
        }
        
        cout << endl << endl;
    }
    else if(trigger ==2)
    {
        for(int i=0; i < userTemp; i++)
        {
            cout << tempChar[i] << " ";
        }
        cout << endl << endl;
        for(int i=0; i < userTemp; i++)
        {
        cout << tempNum[i] << " ";
        }
        cout << endl;
        cout << endl;
    }
}


//selection sorts char array
void sortCharArray(char tempChar[], 
int userTemp, int &swapTemp)
{
    int minimum;//hsmallest item
    int minSlot;//hsmallest index
    char charTemp; //holds index

    for(int i =0; i < userTemp -1; i++)
    {
        minSlot = i;
        minimum = tempChar[i];
        for(int k =i +1; k < userTemp; k++)
        {
            if(tempChar[k] < tempChar[minSlot])
            {
                minSlot = k;
                minimum = tempChar[k];
            }
        }
        if(minimum != tempChar[i])
        {
            swapTemp++;
            charTemp = tempChar[i];
            tempChar[i] = minimum;
            tempChar[minSlot] = charTemp;
        }

    }

}

//selection sorts num array
void sortNumArray(int tempNum[], 
int userTemp, int &swapTemp)
{
    int minimum;//hsmallest item
    int minSlot;//hsmallest index
    int intTemp;//holds index

    for(int i =0; i < userTemp -1; i++)
    {
        minSlot = i;
        minimum = tempNum[i];
        for(int k =i +1; k < userTemp; k++)
        {
            if(tempNum[k] < tempNum[minSlot])
            {
                minSlot = k;
                minimum = tempNum[k];
            }
        }
        if(minimum != tempNum[i])
        {
            swapTemp++;
            intTemp = tempNum[i];
            tempNum[i] = minimum;
            tempNum[minSlot] = intTemp;
        }

    }
}

//duplicates char array
void duplicateChar(char tempChar[], 
int userTemp, char copyArr[])
{
    for(int i=0; i<userTemp; i++)
    {
        copyArr[i] = tempChar[i];
    }
}

//quick sorts with middle index char array
void middleQuickSort(char tempChar[], 
int left, int right, int &swaps)
{
     
    int i = left; // left index
    int k = right;  // right index
    int temp;     // value outside of array
    int pivot = tempChar[((left + right)/2)]; 
    //value to pivot around
    
                                                
    while( i <= k )
    {
        while( tempChar[i] < pivot )
            i++;

    
        while( tempChar[k] > pivot )
            k--;

        if( i <= k )
        {
            temp = tempChar[i];
            tempChar[i] = tempChar[k];
            tempChar[k] = temp;
            i++;
            k--;
        }
    };
    if( left < k )
    {
        middleQuickSort( tempChar, left, k, swaps );
        swaps++;
    }
    if( i < right )
    {
        middleQuickSort( tempChar, i, right, swaps );
        swaps++;
    }
}

//duplicates int array
void duplicateInt(int tempNum[], int userTemp, int copyArr[])
{
    for(int i=0; i<userTemp; i++)
    {
        copyArr[i] = tempNum[i];
    }
}

//quick sorts ints with middle index
void middleQuickSortInt(int tempNum[], int left, int right, int &swaps)
{
     int i = left; // left index
    int k = right;  // right index
    int temp;     // value outside of array
    int pivot = tempNum[((left + right)/2)]; //value to pivot around
    //pivot value to move array around 
                                                
    while( i <= k )
    {
        while( tempNum[i] < pivot )
            i++;

    
        while( tempNum[k] > pivot )
            k--;

        if( i <= k )
        {
            temp = tempNum[i];
            tempNum[i] = tempNum[k];
            tempNum[k] = temp;
            i++;
            k--;
        }
    };
    if( left < k )
    {
        middleQuickSortInt( tempNum, left, k, swaps );
        swaps++;
    }
    if( i < right )
    {
        middleQuickSortInt( tempNum, i, right, swaps );
        swaps++;
    }
}

//quick sorts third value char
void thirdValueSort(char tempChar[], int left, int right, int &swaps)
{
        
    int i = left; // left index
    int k = right;  // right index
    int temp;     // value outside of array
    int pivot = tempChar[left + 3]; //value to pivot around

    while( i <= k )
    {
        while( tempChar[i] < pivot )
            i++;
        while( tempChar[k] > pivot )
            k--;
        if( i <= k )
        {
            temp = tempChar[i];
            tempChar[i] = tempChar[k];
            tempChar[k] = temp;
            i++;
            k--;
        }
    };
    if( left < k )
    {
        middleQuickSort( tempChar, left, k, swaps );
        swaps++;
    }
    if( i < right )
    {
        middleQuickSort( tempChar, i, right, swaps );
        swaps++;
    }
}

//quick sorts third value int
void thirdValueSortInt(int tempNum[], int left, int right, int &swaps)
{
           
    int i = left; // left index
    int k = right;  // right index
    int temp;     // value outside of array
    int pivot = tempNum[left + 3]; //value to pivot around

    while( i <= k )
    {
        while( tempNum[i] < pivot )
            i++;
        while( tempNum[k] > pivot )
            k--;
        if( i <= k )
        {
            temp = tempNum[i];
            tempNum[i] = tempNum[k];
            tempNum[k] = temp;
            i++;
            k--;
        }
    };
    if( left < k )
    {
        middleQuickSortInt( tempNum, left, k, swaps );
        swaps++;
    }
    if( i < right )
    {
        middleQuickSortInt( tempNum, i, right, swaps );
        swaps++;
    }
}

//sequental searches char for 'P'
int sequentalSearch(char tempChar[], int userNum, int &swaps)
{
    char P = 'P'; // holds character for comparing
    int trigger = 0; //tells main what to cout
    swaps++; //holds swaps
    for(int i = 0; i < userNum - 1; i++)
    {
        if(tempChar[i] == P)
        {
            trigger = 1;
            return trigger;
            break;
        }
        else
        {
            swaps++;
        }
    }
 trigger = 0;
 return trigger;
}

//binary searches char for 'P'
int binarySearch(char tempChar[], int userNum, int &swaps)
{
    int i = 0;//temp number holder
    int trigger = 0; //tells main what to cout
    int temp = 0; //holds temp indexes for search
    char P = 'P'; //holds number to compare
    while(i < userNum - 1)
    {
        temp=(i+userNum)/2;
        if(P == tempChar[temp])
        {
            trigger = temp +1;
            break;
            
        }
        else if( P < tempChar[temp])
        {
            userNum=temp -1;
            swaps++;
        }
        else
        {
            i = temp +1;
            swaps++;
        }
        
    }
    return trigger;
}