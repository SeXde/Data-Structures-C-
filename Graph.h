#pragma once

struct DestNode
{
	int data;
	DestNode * next;
};

struct OrigNode
{
	int data;
	DestNode * destNext;
	OrigNode * origNext;
};

class Graph {
	OrigNode * graph;
public:
	Graph();
	virtual ~Graph();
	void addOrigNode(int data);
	void addDestNode(int dataOrig, int dataDest);
	void deleteDestNode(int dataOrig, int dataDest);
	void deleteOrigNode(int data);
	void displayGraph();
};


