/*
 * List.h
 *
 *  Created on: 15 sept. 2020
 *      Author: Usuario
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node * next;
};

class List {
private:
	Node * head;
public:
	List();
	virtual ~List();
	bool isEmpty();
	void addNode(int data);
	void deleteNode(int data);
	void displayList();

};

#endif /* LIST_H_ */
