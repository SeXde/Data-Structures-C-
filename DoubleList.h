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
	int getLength();

public:

	virtual ~DoubleList();
	bool isEmpty();
	void addNode(int data);
	void addNodeAfter(int data);
	void addNodeBefore(int data);
	void addNodeRandom(int data);
	void deleteNode(int data);
	void displayList();
};



