/*
 * List.h
 *
 *  Created on: 15 sept. 2020
 *      Author: Usuario
 */

#pragma once

struct Node
{
	int data;
	Node * next;
};

class List
{
	Node * head = nullptr;

public:

	virtual ~List();
	bool isEmpty();
	void addNode(int data);
	void deleteNode(int data);
	void displayList();
};
