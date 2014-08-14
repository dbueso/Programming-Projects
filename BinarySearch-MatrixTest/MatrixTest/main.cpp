//
//  main.cpp
//  Homework1_2
//
//  Created by Daniel Bueso on 9/6/13.
//  Copyright (c) 2013 Daniel Bueso. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "MatrixIO.h"
#include "Stopwatch.h"

using namespace std;

void matrix_operations () {         // this is the test case that asks for user to input 'n'
//void matrix_operations(int val) { //find the total number of additions required to computer the average of all elements in an nxn matrix
    cout << "Please select a data container to try:\n 1. Vector Matrix\n 2. Matrix Class\n";
    int t = 0, count = 0, j = 0;
    long sum = 0;
    cin >> t;                       // looking for user input on testing vector of vectors or matrix
    if (t == 1) {
        Stopwatch a;                // instantiates stop watch object
        a.start();                  // starts the time
        int n = 0;
        cout << "Please enter a value for 'n' to generate an nxn matrix:\n";
        cin >> n;                   // looking for user input on matrix size
        //n = val;
        vector< vector<int> > vmat (n);     // instantiating vector of vectors object size n
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                vmat[x].push_back(1+(rand() % 300));    // loop through vmat storing random # elements row by row
            }
        }
        for (int i = 0; i < n; ++i) {                   // loop goes through vector matrix
            for (int j = 0; j < n; ++j) {               
                sum += vmat[i][j];                      // summing all elements
                count++;                                // counting # of additions in a vector matrix
            }
        }
        printf("Vector of Vector (%d,%d) Matrix Contains:\n", n,n);
         for (int i = 0; i < n; ++i) {
         for (j = 0; j < n; ++j) {
         //cout << "i:" << i << " j:" << j << endl;
         cout << vmat[i][j] << " ";
         }
         cout << endl;
         }
        a.stop();                                       // stopping stop watch
        cout << "Number of additions required to find the average: " << count << endl;
        cout << "Total Summation of Random Values in Matrix: " << sum << endl;
        cout << "Running Time of Test Case: " << a.ms() << endl;
        a.reset();                                      // resetting stop watch
    } else if (t == 2) {
        Stopwatch a;                                    // instantiating stop watch
        a.start();                                      // starting stop watch
        int n = 0, i = 0, j = 0;
        cout << "Please enter a value for 'n' to generate an nxn matrix:\n";
        cin >> n;                                       // looking for user input on matrix size n
        //n = val;
        Numeric_lib::Matrix<int, 2> mat(n,n);           // instantiating matrix 2D matrix object of type int and size n
        while(i<n){                                     // loop through rows first
            j = 0;
            mat(i,j)=rand() % 100;                      // putting a random elements in columns
            while(j<n){
                mat(i,j)=rand() % 100;                  // putting a random elements in rows
                sum += mat(i,j);                        // summing elements put in matrix
                j++;                                    // counting the number of additions in matrix
            }
            //cout << "test:\n" << mat << endl;
            i++;
        }
        a.stop();                                       // stopping stop watch
        printf("Matrix (%dx%d):\n",n,n);
        cout << mat << endl;
        printf("Number of additions required to compute average: %d\n", (int)mat.size());
        printf("Total Summation of Random Values in Matrix: %ld\n", sum);
        printf("Running Time of Test Case: %f\n", a.ms());
        a.reset();
    } else
        cout << "Invalid Entry! Please run again" << endl;
}

int main()
{
    matrix_operations();
    /*matrix_operations(10);
    matrix_operations(20);
    matrix_operations(100);
    matrix_operations(1000);
    matrix_operations(10000);*/
    
    
    return 0;
}

