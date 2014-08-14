//
//  main.cpp
//  Homework1
//
//  Created by Daniel Bueso on 9/2/13.
//  Copyright (c) 2013 Daniel Bueso. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <deque>

using namespace std;

int i, j, k, m, n, x, z=0;
vector<int> guesses;    // this array keeps track of the values guessed
deque<int> guess;       // this is the sorted array the computer alters to find the value you're guessing
string a;               // string object that takes input from user

struct hwData {         // struct that stores the results of the binary search algorithm
    int range[2];       // data range for a specific test
    int answer;         // the true answer for a specific test
    int comparisons;    // the # of comparisons accrued when guessing
};


void binary_search() {  // algorithm starts here
    while (1) {
        cout << endl << "Binary Search\n" << "Please provide an input range from 1 to x (where 'x' is provided by you or type 'end' to stop test):\n";
        if (cin >> x) { // takes input from user
            break;      // break loop if input is int
        } else {
            cout << "Invalid entry. Type 'end' again to finish test\n";
            cin.clear();    // clears value if non-integer entry
            cin.ignore(std::numeric_limits<streamsize> :: max(), '\n'); // ignores the problematic value
            if (cin >> a) { // looking for string 'end' here
                cout << a << endl;
                if (a == "end")
                    break;  // break if 'end' is entered
            } else {
                cout << "Invalid entry. Type 'end' to finish test\n";                   // loop back around if 'end' wasn't entered second time
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');
            }
        }
    }
    hwData data[12];                                                                    // instantiating 12 hwData struct objects to store results
    printf("Please provide a number for me to guess in the range of 1 to %d:\n", x);    // this value is to help you remember the value you picked, it is not used for computation
    if (a != "end") {                                                                   // if end was not inputted previously then continue
        while (1) {
            if (cin >> i) {                                                             // if input is integer
                cout << "Number for computer to guess is: " << i << endl;
                break;      // break loop
            } else {
                cout << "Invalid entry. Type 'end' to finish test\n";
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');
                if (cin >> a) { // if input is a string
                    cout << a << endl;
                    if (a == "end") // break if 'end' is entered
                        break;
                } else {
                    cout << "Invalid entry. Type 'end' to finish test\n";               // loop back around if 'end' wasn't entered second time
                    cin.clear();
                    cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');
                }
            }
        }
    }
    if (a != "end") {
        for (int k = 1; k <= x; ++k) {                                                  // this deque stores the sorted range of values
            guess.push_back(k);
        }
        for (int y = 0; y < 15; ++y) {                                                  // arbitrary # of loops
            j = guess[(guess.size()-1)/2];                                              // to guess the middle number in the sorted array
            guesses.push_back(j);                                                       // store value that was guessed
            cout << "Value computer guessed: " << j << endl;
            cout << "Is this the correct value? Please say higher, lower, or yes\n";    // asking for user input here
            cin >> a;
            if (a == "lower") {                                                         // if 'lower' look at values left of guess
                while (j <= guess.back()) {                                             // loop checking for values to the right of guess
                    guess.pop_back();                                                   // pop the values out that are greater than guess
                }
            } else if (a == "higher") {                                                 // if 'higherer' look at values right of guess
                while (guess.front() <= j) {                                            // loop checking for values to the left of guess
                    guess.pop_front();                                                  // pop the values out that are less than guess
                }
            } else if (a == "yes") {                                                    // if guess equals the value you had in mind
                cout << "Awesome, I found it! :)" << endl;                              // found it
                break;                                                                  // break out of loop
            } else if (a == "end") {                                                    // if 'end' was selected here, break
                break;
            } else {
                cout << "Invalid Response: Please type 'lower', 'higher', 'yes', or end" << endl;   // no valid responses, loop repeats
            }
        }
    /*cout << endl << "Vector of Guesses Contains:";
    for (vector<int>::iterator it = guesses.begin(); it != guesses.end(); ++it) {
        cout << *it << " ";
    }*/
        data[z].range[0] = 1;
        data[z].range[1] = x;                                                           // storing range data
        data[z].answer = j;                                                             // storing true answer value
        data[z].comparisons = (int)guesses.size();                                      // storing the # of guesses taken to reach target value
        z++;                                                                            // increment to next object
    }
    guess.clear();                                                                      // clear the sorted array
    guesses.clear();                                                                    // clear the guesses array
    if (a == "end") {
        cout << "Range" << "    \tTrue Answer" << "  \t#Comparisons" << endl;           // printing out results if 'end' was entered
        for (int i = 0; i < z; ++i) {
            printf("[%d,%d]   \t%d             \t%d\n",data[i].range[0],data[i].range[1], data[i].answer, data[i].comparisons);
        }
    }
}



int main()
{
    //cout << "Please select an algorithm to try\n 1. Random Guessing Game\n 2. Binary Search Game\n 3. Matrix Operations" << endl;
    //cin >> x;
  
    for (int h = 0; h < 13; ++h) {
        binary_search();
    }

    return 0;
}

