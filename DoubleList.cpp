
#include "DoubleList.h"
#include <iostream>

using namespace std;


bool DoubleList::isEmpty()
{
	return !head;
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
		if (head->next == nullptr)
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
				while (tmp2 != nullptr)
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

void DoubleList::displayList()
{
	Node * tmp = tail;
	while(tmp != nullptr)
	{
		cout <<tmp->data<<endl;
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
