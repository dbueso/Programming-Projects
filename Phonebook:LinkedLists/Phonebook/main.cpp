//
//  main.cpp
//  phonebook
//
//  Created by Daniel Bueso on 10/4/13.
//  Copyright (c) 2013 Daniel Bueso. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <string>
#include "TemplateDoublyLinkedList.h"
#include "Record.h"

using namespace std;

int main()
{
    ifstream ifs;                                                                                       // Declaring input file stream object for text file
    string lt, last_n, first_n;
    char ft;
    int t = 0, count = 0, uin = 0;
    bool flag = false, assign = true;
    Record r;                                                                                           // Declaring Record object r
    DListNode<Record> *dn, *prev_dn;
    vector<TemplateDoublyLinkedList<Record>> phoneBook (26);                                            // Declaring a vector that holds 26 doublylinkedlists
    ifs.open("/home/grads/d/dbueso/PA3/A3/phonebook/Phonebook.txt");                        // Open txt file at specified location
    if (ifs.is_open()) {                                                 // If the input file is open
        while (!ifs.eof()) {                                                                                // Loop until end of file
            ifs >> r;                                                                                       // Inputting data into Record object r
             lt = r.getLastName();                                                                           // Retrieve last name
             ft = lt.front();                                                                                // Get first char of last name
             t = ft;                                                                                         // Assign char to int
             t = t % 65;                                                                                     // Index for vector is achieved by modding the first char of the last name

             if (phoneBook[t].isEmpty()) {                                                                   // If index is empty simply insert
                phoneBook[t].insertLast(r);
             } else
                phoneBook[t].insert(r);                                                                     // If index is not empty use insert function
        }
    } else {
        std::cout << "File failed to open! Please change directory location in main.cpp." << endl;
    }
    for (vector<TemplateDoublyLinkedList<Record>>::iterator it = phoneBook.begin(); it != phoneBook.end(); ++it) {  // Print out all Record element's data
        //std::cout << "In loop!";
        if (!(it->isEmpty())) {
            cout << *it << endl;
        }
    }
    while (1) {                                                                                     // This loop is for user input selection
        cout << "Please input a person's last name to search:\n";
        cin >> last_n;                                                                              // Retrieving last name from user input
        ft = last_n.front();                                                                        // Obtain first char of last name
        t = ft;                                                                                     // Assign char to int
        t = t % 65;                                                                                 // Mod int by 65 to index
        dn = phoneBook[t].getFirst();                                                               // Retrieve first element from indexed list
        while (dn!=phoneBook[t].getAfterLast()) {                                                   // Loop through an indexed entry
            if (last_n.compare(dn->getElem().getLastName()) == 0) {                                 // Compare inputted last name with indexed entries
                if (assign) {
                    prev_dn = dn;
                }
                assign = false;
                flag = true;
                count++;                                                                            // This counter is for multiple entries
            }
            dn = dn->getNext();
        }
        if (flag && count == 1) {                                                                   // Only 1 hit found for last name
            cout << "Last name found! Please input a person's first name to search:\n";
            cin >> first_n;                                                                         // Obtain first name from user input
            if (first_n.compare(prev_dn->getElem().getFirstName()) == 0) {                          // Compare first name with indexed entries
                assign = true;
                cout << "First name found! Returning Phone Number:\n";
                cout << prev_dn->getElem().getPhoneNum() << endl;                                   // Displaying phone number if names are found
                //break;
            } else {
                cout << "First not name found!\n";
            }
        } else if (flag && count > 1) {                                                             // Multiple hits found for last name
            count = 0;
            assign = true;
            dn = prev_dn;
            cout << "Multiple last names found! Please input the person's first name to search:\n";
            cin >> first_n;                                                                         // Obtain first name from user input
            while (dn!=phoneBook[t].getAfterLast()) {                                               // Retrieve first element from indexed list by last name
                if (first_n.compare(dn->getElem().getFirstName()) == 0) {                           // Compare user input with first names
                    if (assign) {
                        prev_dn = dn;
                    }
                    assign = false;
                    count++;                                                                        // Increment counter for multiple entries
                }
                dn = dn->getNext();
            }
            if (count == 1) {                                                                       // Single first name hit
                cout << "First name found! Returning Phone Number!\n";
                //cin >> uin;
                //if (uin == prev_dn->getElem().getUin()) {
                    assign = true;
                    //cout << "UIN found! Returning Phone Number:\n";
                    cout << prev_dn->getElem().getPhoneNum() << endl;
                    //break;
                //}
            } else if (count > 1) {                                                                 // Multiple first name hits
                cout << "Multiple first names found! Please enter UIN:\n";
                cin >> uin;                                                                         // Ask for UIN from user
                while (prev_dn!=phoneBook[t].getAfterLast()) {                                      // Retrieve first element from indexed list by first name
                    if (uin == prev_dn->getElem().getUin()) {                                       // If UIN matches
                        assign = true;
                        cout << "UIN found! Returning Phone Number:\n";
                        cout << prev_dn->getElem().getPhoneNum() << endl;                           // Return phone number here
                        break;
                    }
                    prev_dn = prev_dn->getNext();
                }
                if (!assign) {
                    cout << "UIN not found!" << endl;
                }
                //break;
            }
            if (!assign) {
            cout << "First name not found!" << endl;
            }
        } else {
            cout << "Invalid Entry! Person not found." << endl;                                     // Last name not found
            cin.clear();                                                                            // Clear out cin buffer (equal to null)
            cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');                             // Ignore previous value in cin (the null value)
        }
        flag = false;
        assign = true;
        count = 0;
    }
    
    return 0;
}

