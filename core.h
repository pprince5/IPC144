
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Siya khanna
Student ID#: 145964227
Email      : skhanna49@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef CORE_H
#define CORE_H



//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//gurantees that a valid integer is entered
int inputInt(void);

//gurantees that a valid positive integer is entered(greater than zero)
int inputIntPositive(void);

//gurantees that the value entered is between the permitted range
int inputIntRange(int MIN_RANGE, int MAX_RANGE);

//gurantees the the character entered is present in the string
char inputCharOption(const char[]);

//obtains user input for a string
void inputCString(char*, int MIN_CHAR, int MAX_CHAR);

//obtains user input for a number
void inputCStringNumbers(char* str, int minChar, int maxChar);


//displays an array of 10 digits of a phone number
void displayFormattedPhone(const char*);

#endif // !CORE_H

