

#include "DoubleList.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>



bool DoubleList::isEmpty()
{
	return !head;
}

int DoubleList::getLength()
{
	int length = 0;
	Node * tmp = head;
	while(tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return length;
}

void DoubleList::addNode(int data)
{
	Node * tmp = new Node();
	tmp->data = data;
	if (isEmpty())
	{
		tmp->next = nullptr;
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
		tmp ->next = head;
		tmp->prev = nullptr;

	}
	tmp->prev = nullptr;
	head = tmp;
}

void DoubleList::deleteNode(int data)
{
	if (!isEmpty())
	{
		Node * tmp = head;
		if ((!head->next) && (head->data == data))
		{
			delete tmp;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node * tmp2 = tail;
			if (tmp->data == data)
			{
				head = head->next;
				head->prev = nullptr;
				delete tmp;
			}
			else if (tmp2->data == data)
			{
				tail = tail->prev;
				tail->next = nullptr;
				delete tmp2;
			}
			else
			{
				tmp2 = head;
				while (tmp2)
				{
					if (tmp2->data == data)
					{
						tmp->next = tmp2->next;
						tmp2->next->prev = tmp;
						delete tmp2;
						break;

					}
					tmp = tmp2;
					tmp2 = tmp2->next;
				}
			}
		}

	}
}


void DoubleList::addNodeAfter(int data)
{
	Node * tmp = new Node();
	tmp->data = data;
	if (isEmpty())
	{
		tmp->prev = nullptr;
		head = tmp;
	}
	else
	{
		tail->next = tmp;
		tmp->prev = tail;
	}
	tail = tmp;
	tmp->next = nullptr;
}
void DoubleList::addNodeBefore(int data)
{
	Node * tmp = new Node();
	tmp->data = data;
	if (isEmpty())
	{
		tmp->next = nullptr;
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
		tmp ->next = head;
		tmp->prev = nullptr;

	}
	tmp->prev = nullptr;
	head = tmp;
}

void DoubleList::addNodeRandom(int data)
{
	srand(time(nullptr));
	int randNumber = rand() % (getLength() +1);
	if (randNumber == 0)
	{
		addNodeBefore(data);
	}
	else if (randNumber == getLength())
	{
		addNodeAfter(data);
	}
	else
	{
		Node * tmp = head;
		for (int i = 1;i<randNumber;i++) tmp = tmp->next;
		Node * tmp2 = new Node;
		tmp2->data = data;
		tmp2->prev = tmp;
		tmp2->next = tmp->next;
		tmp->next = tmp2;
		tmp2->next->prev = tmp2;


	}

}

void DoubleList::displayList()
{
	Node * tmp = tail;
	while(tmp)
	{
		std::cout <<tmp->data<<std::endl;
		tmp = tmp->prev;
	}
}


DoubleList::~DoubleList()
{
	Node * tmp = head;
	Node * tmp2 = tail;
	while(head != tail)
	{
		tmp = head;
		tmp2 = tail;
		head = head->next;
		tail = tail->prev;
		delete tmp;
		delete tmp2;
	}
	delete tmp;
	delete tmp2;
	delete head;
}
