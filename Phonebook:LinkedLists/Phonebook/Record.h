//
//  Record.h
//  phonebook
//
//  Created by Daniel Bueso on 10/4/13.
//  Copyright (c) 2013 Daniel Bueso. All rights reserved.
//


#include <string.h>
#include <sstream>
#include <string>

using namespace std;

class Record {
private:
    string last_name, first_name;
    int uin, phone_num;
public:
    Record(): last_name(), first_name(), uin(0), phone_num(0) {};
    
    bool operator()(const Record &r) {                                              // Overloading Less-than Operator definition
        if (strcmp(last_name.c_str(), r.getLastName().c_str()) < 0) {               // If "this" last name is less than another, return true
            return true;
        } else if (strcmp(last_name.c_str(), r.getLastName().c_str()) > 0) {        // If "this" last name is greater than another, return false
            return false;
        } else {
            if (strcmp(first_name.c_str(), r.getFirstName().c_str()) < 0) {         // If "this" first name is less than another, return true
                return true;
            } else if (strcmp(first_name.c_str(), r.getFirstName().c_str()) > 0) {  // If "this" first name is greater than another, return false
                return false;
            } else {
                if (uin < r.getUin()) {                                             // If "this" uin is less than another, return true
                    return true;
                } else if (uin > r.getUin()) {                                      // If "this" uin is greater than another, return false
                    return false;
                } else {
                    return false;
                }
            }
        }
    }

    friend ifstream& operator>> (ifstream &in, Record &r);              // Overloading Input Operator declaration

    string getLastName() const { return last_name; }
    string getFirstName() const { return first_name; }
    int getUin() const { return uin; }
    int getPhoneNum() const { return phone_num; }
    
};

ifstream& operator>> (ifstream &in, Record &r) {                        // Overloading Input Operator definition
    string str,line;
    stringstream ss;
    
    if (in.is_open()) {                                                 // If the input file is open
        while (!in.eof()) {                                             // Loop until end of file is reached
            getline(in, str);                                           // Get lines from the input file
            if (!(str.size() == 0)) {                                       // If line is not empty
                line.append(str+" ");                                   // Appending all of a persons contact info to a single space delimited string
            } else
                break;                                                // Break after looping through a person's info
        }
    }
    //std::cout << line << " ";
    ss << line;                                                         // Assign person's info to a stringstream
    ss >> r.last_name >> r.first_name >> r.uin >> r.phone_num;          // Extract persons data from stringstream and storing into Record parameters
    
    return in;
}

ostream& operator<< (ostream &out, const Record &r) {                   // Overloading Output Operator definition - Prints out an entire Record
    out << r.getLastName() << " ";                                      // Putting last_name into out buffer
    out << r.getFirstName() << " ";                                     // Putting first_name into out buffer
    out << r.getUin() << " ";                                           // Putting uin into out buffer
    out << r.getPhoneNum() << endl;                                     // Putting phone number into out buffer
    return out;                                                         // Returning out object
}


