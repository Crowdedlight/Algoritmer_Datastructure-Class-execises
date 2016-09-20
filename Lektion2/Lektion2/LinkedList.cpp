/*
* LinkedList.cpp
*
*  Created on: Sep 9, 2015
*      Author: Simon Mathiesen
*/

#include "LinkedList.h"

LinkedList::LinkedList(Node * n) {
	head = n;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}



void LinkedList::add(int val) {
	std::cout << "add" << std::endl;
	Node * newNode = new Node(val);
	Node * current = head;
	while (current)
	{
		if (current->next == NULL) {
			current->next = newNode;
			break;
		}
		current = current->next;
	}
}
