// Program:		Doubly Linked List and Templates
// Author:		Holly Eaton
// Description:	Program which uses a template to implement a doubly linked list. Test.cpp
//				implements tests and demonstrats this using a float and a class for starfleet officers.

#include "StarfleetOfficer.h"

StarfleetOfficer::StarfleetOfficer()
{
    name = "";
    IdNumber = 0;
}

StarfleetOfficer::StarfleetOfficer(string officerName, int officerId)
{
    name = officerName;
    IdNumber = officerId;
}

bool operator== (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2)
{
	if (officer1.name == officer2.name)
		return true;
	return false;
}

bool operator!= (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2)
{
	return !(officer1 == officer2);
}

bool operator> (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2)
{
	if (officer1.name > officer2.name)
		return true;
	return false;
}

bool operator< (const StarfleetOfficer &officer1, const StarfleetOfficer &officer2)
{
	if (officer1.name < officer2.name)
		return true;
	return false;
}

ostream& operator<< (ostream& stream, const StarfleetOfficer &someOfficer)
{
    stream << someOfficer.name << " " << someOfficer.IdNumber;
    return stream;
}