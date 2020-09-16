#pragma once

struct Node
{
	int data;
	Node * next, * prev;
};

class DoubleList
{
	Node * head = nullptr;
	Node * tail = nullptr;
public:
	virtual ~DoubleList();
	bool isEmpty();
	void addNode(int data);
	void deleteNode(int data);
	void displayList();
};


