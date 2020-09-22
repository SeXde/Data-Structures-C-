#include "Graph.h"
#include <iostream>

Graph::Graph() {

	graph = nullptr;

}

void Graph::addOrigNode(int data)
{
	OrigNode * tmp = new OrigNode;
	tmp->data = data;
	tmp->destNext = nullptr;
	tmp->origNext = graph;
	graph = tmp;
}

void Graph::addDestNode(int dataOrig, int dataDest)
{
	if (graph)
	{
		DestNode * tmp = new DestNode;
		tmp->data = dataDest;
		OrigNode * tmp2 = graph;
		while(tmp2)
		{
			if (tmp2->data == dataOrig)
			{
				tmp->next = tmp2->destNext;
				tmp2->destNext = tmp;
				break;
			}
			tmp2 = tmp2->origNext;
		}

		if (!tmp2) delete tmp;

	}
}


void Graph::deleteDestNode(int dataOrig, int dataDest)
{
	if (graph)
	{
		OrigNode * tmpOrig = graph;

		while (tmpOrig)
		{
			if (tmpOrig->data == dataOrig) break;
			tmpOrig = tmpOrig->origNext;
		}

		DestNode * tmpDest = tmpOrig->destNext;

		if (tmpDest->data == dataDest)
		{
			tmpOrig->destNext = tmpDest->next;
			delete tmpDest;
		}
		else
		{
			DestNode * tmpDest2 = tmpDest;
			while (tmpDest)
			{
				if (tmpDest->data == dataDest)
				{
					if (!tmpDest->next) tmpDest2->next = nullptr;
					else tmpDest2->next = tmpDest->next;
					delete tmpDest;
					break;
				}
				tmpDest2 = tmpDest;
				tmpDest = tmpDest->next;
			}
		}
	}
}

void Graph::deleteOrigNode(int data)
{
	if (graph)
	{
		OrigNode *
	}
}

void Graph::displayGraph()
{
	if (graph)
	{
		OrigNode * tmpOrig = graph;
		DestNode * tmpDest;
		std::cout <<"......................"<<std::endl;
		while (tmpOrig)
		{
			std::cout <<tmpOrig->data<<std::endl;
			std::cout <<"-------------------"<<std::endl;
			tmpDest = tmpOrig->destNext;
			while(tmpDest)
			{
				std::cout <<tmpDest->data<<std::endl;
				tmpDest = tmpDest->next;
			}
			std::cout <<"-------------------"<<std::endl;
			std::cout <<"......................"<<std::endl;
			tmpOrig = tmpOrig->origNext;
		}
	}

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

