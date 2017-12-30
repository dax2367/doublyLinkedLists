// Program:		Doubly Linked List and Templates
// Author:		Holly Eaton
// Description:	Program which uses a template to implement a doubly linked list. Test.cpp
//				implements tests and demonstrats this using a float and a class for starfleet officers.

#ifndef STARFLEETOFFICER_H
#define STARFLEETOFFICER_H

#include <iostream>
#include <string>

using namespace std;

class StarfleetOfficer
{
public:
	StarfleetOfficer();
    StarfleetOfficer(string officerName, int officerId = 999);
	friend bool operator== (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2);
	friend bool operator!= (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2);
	friend bool operator> (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2);
	friend bool operator< (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2);
    friend ostream& operator<< (ostream& stream, const StarfleetOfficer &someOfficer); 

	string name;
	int IdNumber;
};

#endif