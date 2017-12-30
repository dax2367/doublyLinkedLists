// Program:		Doubly Linked List and Templates
// Author:		Holly Eaton
// Description:	Program which uses a template to implement a doubly linked list. Test.cpp
//				implements tests and demonstrats this using a float and a class for starfleet officers.

#include <iostream>
#include <cctype>
#include <string>

#include "StarfleetOfficer.h"
#include "eatonDoublyLinkedList.h"


using namespace std;

void main()
{
	dblLL<float> testList1;
	dblLL<StarfleetOfficer> testList2;


	testList1.insert(3.14);
	testList1.insert(2.71);
	testList1.insert(1.23);
	testList1.insert(2.02);
	testList1.insert(3.03);
	testList1.print();
	testList1.remove(1.23);
	testList1.printReverse();
	cout<< testList1.count() << " items in list\n";
	testList1.removeAll();
	testList1.count();
	
	StarfleetOfficer officer("Sisko", 11);
	if (testList2.insert(officer))
		cout << "Officer successfully added\n";
	testList2.print();
	officer.name = "Kirk";
	officer.IdNumber = 69;
	if (testList2.insert(officer))
		cout << "Officer successfully added\n";
	cout<<testList2.count()<< " items in list\n";
	if (testList2.remove(officer))
		cout << "Officer successfully removed\n";
	testList2.print();
	testList2.removeAll();
	cout<<testList2.count()<< " items in list\n";

	cin.get();
}
