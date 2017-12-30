// Program:		Doubly Linked List and Templates
// Author:		Holly Eaton
// Description:	Program which uses a template to implement a doubly linked list. Test.cpp
//				implements tests and demonstrats this using a float and a class for starfleet officers.

#include <iostream>

#ifndef dblLL_H
#define dblLL_H

using namespace std;

template <class dataType>
class Node
{
public:
	dataType info;
	Node<dataType> *next;
	Node<dataType> *prev;
};

template <class dataType>
class dblLL
{
private:
	Node<dataType> *head;
	Node<dataType> *tail;

public:
	dblLL::dblLL();
	~dblLL();
	void removeNode(Node<dataType> *n);
	void displayNode(Node<dataType> *n);
	bool insert(dataType someData);
	bool remove(dataType someData);
	void removeAll();
	void print();
	int count();
	void printReverse();
};

template <class dataType>
dblLL<dataType>::dblLL()
{
	head = NULL;
	tail = NULL;
}

template <class dataType>
dblLL<dataType>::~dblLL()
{
	removeAll();
}

//=====================================================================
//Function info: insert
//
//Description: adds a non duplicate item to an ordered linked list
//
//Parameters: (I) info - the info being added to the linked list
//
//Return: true - the item was successfully added
//			false - the item was not added
//=====================================================================
template <class dataType>
bool dblLL<dataType>::insert(dataType someData)
{
	//create node
	Node<dataType> *newNode = new Node<dataType>;

	//initialize node
	newNode->info = someData;
	newNode->next = NULL;

	//case: head was empty (empty list)
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		return true;
	}
	//case: item goes first (in the list)
	else if (newNode->info < head->info)
	{
		newNode->next = head; //this must always go first or you break the chain
		head->prev = newNode;
		head = newNode;
		return true;
	}
	//case: item goes last (in the list)
	else if (newNode->info > tail->info)
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		return true;
	}
	//case: item goes in the middle
	else
	{
		Node<dataType> *current = head->next;
		while (current->info < newNode->info)
			current = current->next;
		//case: duplicate infos
		if (current != NULL && current->info == newNode->info)
			return false;
		else
		{
			newNode->next = current;
			newNode->prev = current->prev;
			current->prev->next = newNode;
			current->prev = newNode;
			return true;
		}
	}

	return false;
}
//=====================================================================
//Function info: remove
//
//Description: removes an item from an ordered linked list
//
//Parameters: (I) info - the info to be removed from the linked list
//
//Return: true - the item was successfully removed
//			false - the item was not removed
//=====================================================================
template <class dataType>
bool dblLL<dataType>::remove(dataType someData)
{
	//case: list is empty
	if (head == NULL)
		return false;
	//case: first item is being deleted
	if (someData == head->info)
	{
		Node<dataType> *nodeToDelete = head;
		head = head->next;
		delete nodeToDelete;
		return true;
	}
	//case: last item is being deleted
	if (someData == tail->info)
	{
		Node<dataType> *nodeToDelete = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete nodeToDelete;
		return true;
	}
	//case: item being deleted is in the middle of the list
	//find the node to delete
	Node<dataType> *current = head->next;
	Node<dataType> *prev = head;
	while (current != NULL && current->info < someData)
	{
		prev = current;
		current = current->next;
	}
	if (current != NULL && current->info == someData)
	{
		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
		return true;
	}
	//case: not found
	return false;
}
//=====================================================================
//Function info: removeALL
//
//Description: removes all items from a linked list
//=====================================================================
template <class dataType>
void dblLL<dataType>::removeAll()
{
	if (head !=NULL)
		removeNode(head);
	head = NULL;
	tail = NULL;
	std::cout <<"All items removed\n";
}
//=====================================================================
//Function info: removeNode
//
//Description: removes a node from a linked list
//
//Parameters: (I)n - the node to be removed
//=====================================================================
template <class dataType>
void dblLL<dataType>::removeNode(Node<dataType> *n)
{
	if (n->next != NULL)
		removeNode(n->next);
	delete n;
}
//=====================================================================
//Function info: print
//
//Description: prints all the items of a linked list
//=====================================================================
template <class dataType>
void dblLL<dataType>::print()
{
	if (head != NULL)
		displayNode(head);
	else
		std::cout << "No items in list\n";
}

//=====================================================================
//Function info: displayNode
//
//Description: displays the data of one node in the console window
//
//Parameters: (I) n - the node whose data is to be displayed
//=====================================================================
template <class dataType>
void dblLL<dataType>::displayNode(Node<dataType> *n)
{
	if (n->next != NULL)
	{
		std::cout << n->info << ", ";
		displayNode(n->next);
	}
	if (n->next == NULL)
		std::cout << n->info << std::endl;
}

//=====================================================================
//Function info: count
//
//Description: determines and outputs the number of items in a linked list
//				in the console window
//=====================================================================
template <class dataType>
int dblLL<dataType>::count()
{
	Node<dataType> *temp = head;
	int total = 0;

	if (head == NULL)
	{
		return 0;
	}

	while (temp != tail)
	{
		total++;
		temp = temp->next;
	}

	return ++total;
}

//=====================================================================
//Function info: printReverse
//
//Description: displays the contents of an ordered link list in
//				reverse order
//=====================================================================
template <class dataType>
void dblLL<dataType>::printReverse()
{
	Node<dataType> *temp = tail;
	if (tail == NULL)
		return;
	while (temp != head)
	{
		std::cout << temp->info << ", ";
		temp = temp->prev;
	}
	std::cout << head->info << "\n";
}

#endif