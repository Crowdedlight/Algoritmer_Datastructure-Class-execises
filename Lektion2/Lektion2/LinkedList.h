/*
* LinkedList.h
*
*  Created on: Sep 9, 2015
*      Author: Simon Mathiesen
*/
#include <iostream>

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class Node
{
public:
	int data;
	Node * next;
	Node(int d) {
		data = d;
		next = NULL;
	}
	virtual ~Node() {};
};


class LinkedList {
public:
	LinkedList(Node * n);
	virtual ~LinkedList();

	Node * head;

	void add(int val);
	void remove(int val);
	void print();
	bool test(int val);
};

#endif /* LINKEDLIST_H_ */

