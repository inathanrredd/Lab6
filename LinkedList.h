#pragma once
#include <string>
#include "LinkedListInterface.h"
#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct Node {
        T data;
        Node* next;
        Node (const T& the_data, Node* next_val = NULL) :
        data(the_data) {next = next_val;}
    };
    Node *myList;
    int numItems;

public:

	LinkedList(void) {
        cout << "In constructor" << endl;
        myList = NULL;
        numItems = 0;
    };
	~LinkedList(void) {
        cout << "In destructor" << endl;
		clear();
    };

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value) {
		for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {
			if (ptr->data == value) {
				cout << "This value is already in the list" << endl;
				return;
			}
		}
        cout << "In insertHead" << endl;
        Node *ptr = myList;
        myList = new Node(value);
        myList->next = ptr;
		numItems++;
    }

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
        cout << "In insertTail" << endl;
		if (numItems==0) {
			myList = new Node(value);
			numItems++;
		}
		for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {

			if (ptr->data == value) {
				cout << "This value is already in the list" << endl;
				return;
			}
			if (ptr->next==NULL) {
				cout << "Found the last item in list" << endl;
				Node *last = new Node(value);
				ptr->next = last;
				numItems++;
				return;
			}
		}
    }

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode) {
        cout << "In insertAfter" << endl;
		for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {
			if (ptr->data == value) {
				cout << "This value is already in the list" << endl;
				return;
			}
		}
		for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {
			if (ptr->data == insertionNode) {
				Node *before = ptr;
				ptr = new Node(value);
				ptr->next = before->next;
				before->next = ptr;
				numItems++;
			}
		}

    }

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value) {
        cout << "In remove" << endl;
		Node *match;
		// cout << match->data << " " << match->next << endl;
		for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {
			if (ptr->data == value) {
				if (ptr == myList) {
					myList = ptr->next;
					delete ptr;
					numItems--;
					return;
				}
				else {
					match = ptr;
					for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {
						if (ptr->next == match) {
							ptr->next = match->next;
							numItems--;
							delete match;
						}
					}
					return;
				}
			}
		}
		cout << "This value is not in the list" << endl;
    }

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear() {
        cout << "In clear" << endl;

		while(myList != NULL) {
			Node *current = myList;
			myList = myList->next;
			delete current;
		}
		numItems = 0;
    }

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
        cout << "In at" << endl;
		int i = 0;
		// if (index >=numItems) {
		// 	throw out_of_range("This index does not exist in the list");
		// }
		for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {
			if (index==i) {
				return ptr->data;
			}
			i++;
		}
		throw out_of_range("This index does not exist in the list");
    }

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size() {
        cout << "In size" << endl;
        return numItems;
    }

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString() {
        stringstream ss;
		if (myList == NULL) {
			string str = "";
			return str;
		}
		int i = 1;
        for (Node *ptr = myList; ptr != NULL; ptr = ptr->next) {
			if (i == numItems)
				ss << ptr->data;
			else
            	ss << ptr->data << " ";
			i++;
        }
        return ss.str();
    }

};
