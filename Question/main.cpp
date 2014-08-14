//
//  main.cpp
//  Question
//
//  Created by Daniel Bueso on 9/7/13.
//  Copyright (c) 2013 Daniel Bueso. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "Question.h"

int myrandom (int i) { return std::rand()%i;}

int main()
{
    ifstream ifs;                                                                                   // Defining Input File Stream Obj
    Question q;                                                                                     // Question Obj
    vector<int> guesses;                                                                            // This vector keeps the values of possible index guesses
    srand(unsigned(time(NULL)));                                                                    // srand defines how rand values are chosen
    int k, j = 1, m;                                                                                // Integer variables
    float pass = 0, score = 0;                                                                      // Float for pass and score variables

    ifs.open("/home/grads/d/dbueso/PA1/Question/questions.txt");                                    // Open txt file at specified location
    cout << "Please Enter a Container to Try: \n1. Vector\n2. List\n";
    
    for (int i = 0; i < 15; ++i) {
        guesses.push_back(i);                                                                       // Assigning a set of values 0 to 14 in vector guesses
    }
    
    while (1) {                                                                                     // This loop is for user input selection
        cin >> m;
        if (m == 1) {   
            break;                                                                                  // Vector selected, break
        }
        else if (m == 2) {
            break;                                                                                  // List selected, break
        }
        else {
            cout << "Invalid Entry! Please input either '1' or '2'" << endl;                        // User did not enter a 1 or 2 for input
            cin.clear();                                                                            // Clear out cin buffer (equal to null)
            cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');                             // Ignore previous value in cin (the null value)
        }
    }
    
    
    
    
    //Vector Implementation starts here
    if (m == 1) {   
        vector<Question> vectQuestions;                                                             // Instantiating a vector of type Question
        while (!ifs.eof()) {                                                                        // Loop while end-of-file has not been reached
            ifs >> q;                                                                               // Using overloading >> operator to store file data
            if (q.get_Q() != " ") {
                vectQuestions.push_back(q);                                                         // Only push_back vector objects if the object has values set
            }
        }
    
        /*for (int i = 0; i < vectQuestions.size(); ++i) {                                          // Printing out objects stored in vectQuestions
            cout << vectQuestions[i] << endl;
         }*/
                                                                                                    // Using built-in random generator
        random_shuffle ( guesses.begin(), guesses.end(), myrandom);                                 // Swaps values in guesses vector
    
        vector<int>::iterator it = guesses.begin();
        while (j < 11) {
        //for (std::vector<int>::iterator it=guesses.begin(); it!=guesses.end(); ++it) {              // Randomly select questions
            cout << "Question #" << j << ": ";
            cout << vectQuestions[*it] << endl;
            while (1) {                                                                             // Input loop
                if (cin >> k) {                                                                     // Checking for integer input from user
                    if (k == vectQuestions[*it].get_Ans()) {                                        // If input equals correct answer choice
                        cout << "That's right you're a smart! :)\n\n";
                        pass++;
                        break;                                                                      // Break out of loop
                    } else {
                        cout << "Sorry you're incorrect :(\n\n";                                    // User selected incorrect answer
                        break;                                                                      // Break out of loop
                    }
                } else {
                    cout << "Invalid entry! Please try again\n";                                    // User entered non-integer value
                    cin.clear();                                                                    // Clear out cin buffer (equal to null)
                    cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');                     // Ignore previous value in cin (the null value)
                }
            }
            ++it;
            j++;                                                                                    // Increment question #
        }
        score = (pass/10*100);
        cout << "Score: " << score << endl;                                                         // User score
        if (score > 70) {
            cout << "Congratulations you passed! :)\n";                                             // User Pass
        } else
            cout << "I am sorry you failed. Please try again!\n";                                   // User Fail
        
        cout << "Equality test result: " << (vectQuestions[0] == vectQuestions[0]) << endl;          // Equality Operator Test
        
    } //List Implementation starts here
    else if (m == 2) {
        list<Question> listQuestions;
        while (!ifs.eof()) {                                                                         // Loop while end-of-file has not been reached
            ifs >> q;                                                                                // Using overloading >> operator to store file data
            if (q.get_Q() != " ") {                                                                  // Only push_back vector objects if the object has values set
                listQuestions.push_back(q);
            }
        }
        
        /*int n = 0;
        while (listQuestions.size() > n) {                                                          // Printing out objects stored in listQuestions
            list<Question>::iterator it = next(listQuestions.begin(), n);
            cout << *it << endl;
            n++;
        }*/
        
        random_shuffle ( guesses.begin(), guesses.end(), myrandom);                                 // Swaps values in guesses vector
        
        j = 1;
        vector<int>::iterator it = guesses.begin();
        while (j < 11) {
        //for (std::vector<int>::iterator it=guesses.begin(); it!=guesses.end(); ++it) {              // Randomly select questions
            cout << "Question #" << j << ": ";
            list<Question>::iterator it2 = next(listQuestions.begin(), *it);                        // it2 points to the element at index *it
            cout << *it2 << endl;
            while (1) {                                                                             // Input loop
                if (cin >> k) {                                                                     // Checking for integer input from user
                    if (k == it2->get_Ans()) {                                                      // If input equals correct answer choice
                        cout << "That's right you're a smart! :)\n\n";
                        pass++;
                        break;                                                                      // Break out of loop
                    } else {
                        cout << "Sorry you're incorrect :(\n\n";                                    // User selected incorrect answer
                        break;                                                                      // Break out of loop
                    }
                } else {
                    cout << "Invalid entry! Please try again\n";                                    // User entered non-integer value
                    cin.clear();                                                                    // Clear out cin buffer (equal to null)
                    cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');                     // Ignore previous value in cin (the null value)
                }
            }
            ++it;
            j++;                                                                                    // Increment question #
        }
        score = (pass/10*100);
        cout << "Score: " << score << endl;                                                         // User score
        if (score > 70) {
            cout << "Congratulations you passed! :)\n";                                             // User Pass
        } else
            cout << "I am sorry you failed. Please try again!\n";                                   // User Fail
    }
    
    
    return 0;
}

