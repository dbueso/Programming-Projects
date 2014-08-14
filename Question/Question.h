//
//  Question.h
//  Question
//
//  Created by Daniel Bueso on 9/7/13.
//  Copyright (c) 2013 Daniel Bueso. All rights reserved.
//

#ifndef Question_Question_h
#define Question_Question_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

class Question {
private:
    string question_statement;
    vector<string> choices;
    int answer;
public:
    Question()                                                          // Constructor
    {
        question_statement = " ";
        choices.clear();
        answer = 0;
        
    }         
    
    Question (string s, vector<string> sv, int ans=0)                   // Call Assignment
    {
        question_statement = s;
        choices = sv;
        answer = ans;
        
    }
    
    friend bool operator==(const Question &q1, const Question &q2);     // Equalting Operator declaration
    friend ifstream &operator>> (ifstream &in, Question &q);            // Overloading Input Operator declaration
    friend ostream &operator<< (ostream &out, const Question &q);       // Overloading Output Operator declaration
        
    string get_Q() const {return question_statement;}                   // Get for Question
    int get_Ans() const {return answer;}                                // Get for Correct Answer
 
};


bool operator==(const Question &q1, const Question &q2) {               // Equality Operator (for 2 Question objects)
    if (q1.question_statement == q2.question_statement && q1.answer == q2.answer) { // if questions and answers are equal
        for (int i = 0; i < q1.choices.size(); ++i) {
            if (q1.choices[i] != q2.choices[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;									
    }
}

ifstream &operator>>(ifstream& in, Question &q) {                       // Overloading Input Operator
    string line, question, ans_choice;
    size_t found;
    int k = 0;
    q.question_statement = " ";
    q.choices.clear();                                                  // clearing current vector container
    q.answer = 0;
    
    if (in.is_open()) {
        while (!in.eof()) {
            getline(in,line);                                           // gets a line in the text file and stores into string line
                found = line.find("Choose");                            // looking for 'Choose' this line signifies a question
            if (found!=string::npos) {                                  // found a question statement
                //question = line;
                q.question_statement = line;
                //cout << "Question: " << line << endl;                   // insert question into question statement obj
            } else if (line.size() == 0) {
                //break;                                                  // break out of loop when empty line is found
                continue;
            } else {
                int scan_value = sscanf(line.c_str(),"%d", &k);         // converting string to c_string and looking for just an integer
                if (scan_value == 0) {                                  // if an only integer does not exist
                    //ans_choice = line;
                    q.choices.push_back(line);                          // an answer choice gets stored in choices
                    //cout << "Answer Choice: " << line << endl;
                } else {
                    k = atoi(line.c_str());                             // if only an integer, found answer choice (converts string to int)
                    q.answer = k;
                    break;
                    //cout << "Correct Answer: " << k << endl;
                }
                
            }
        }
    }
   
    return in;
}
                                                                        // This function is called to display a question to user
ostream &operator<< (ostream& out, const Question &q) {                 // Overloading Output Operator
    out << q.get_Q() << endl;                                           // Print out question_statement
    for (int i = 0; i < q.choices.size(); ++i) {                        // Print out vector choices
        out << i+1 << ". " << q.choices[i] << endl;
    }
    //out << " Answer: " << q.get_Ans() << endl;
    return out;
}


  



#endif
