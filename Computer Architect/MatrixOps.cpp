/* CS3339 Assignment 6 Problem 1
 * Modified by [your name here and netID here]
 * Original Lee Hinkle
 * Some references used: https://software.intel.com/en-us/node/529735
 *                       http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
 * Timing code based off work by Dr. Martin Burtscher, Texas State University
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

int main()
{
    cout << "Project 6 Array Traversal: ";
    int size = 900;  // this is the #rows and #columns or n in nxn matrix
    cout << " Array size = " << "FIXME " << " Bytes" << endl;
    int *A[size];

    for (int r=0; r<size; r++){
        A[r] = (int *)malloc(size * sizeof(int));
        if (A[r] == NULL) {
            printf( "\n ERROR: Can't allocate memory for matrix. Aborting... \n\n");
            free(*A);
            return 1;
        }
    }

    double runtime; // for time measurements
    struct timeval start, end;  // for time measurements
    //initialize matrix
    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++){
            A[r][c] = (int)r*c+1;
        }
    }

    gettimeofday(&start, NULL);  // start timer
    // perform matrix operation - process row first, column increments on inner loop
    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++){
            A[r][c] = 2*A[r][c];
        }
    }
    gettimeofday(&end, NULL);  // stop timer
    //compute and display results
    runtime = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
    printf("by row compute time: %.4f seconds ", runtime);
    printf("mega_elements/sec: %.3f\n", size*size*0.000001 / runtime);

    //re-initialize matrix outside of timing measurements
    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++){
            A[r][c] = (int)r*c+1;
        }
    }
    gettimeofday(&start, NULL);  // start timer
    // perform matrix operation - process column first, row increments on inner loop
    cout << "TODO: implement column first traversal" << endl; //delete this when implemented
    gettimeofday(&end, NULL);  // stop timer
    //compute and display results
    runtime = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
    printf("by column compute time: %.4f seconds ", runtime);
    printf("mega_elements/sec: %.3f\n", size*size*0.000001 / runtime);
    free(*A);
    return 0;
}
