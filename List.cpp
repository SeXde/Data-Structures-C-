#include "List.h"
#include <iostream>



bool List::isEmpty(){
	return !head;
}

void List::addNode(int data){
	Node * tmp = new Node();
	tmp->data = data;
	tmp->next = head;
	head = tmp;

}

void List::deleteNode(int data){
	Node * tmp2 = head;
	if (tmp2){
		if (tmp2->data == data){
			head = tmp2->next;
			delete tmp2;
		}else{
			Node * tmp = tmp2;
			while(tmp2){
				if (tmp2->data == data){
					tmp->next = tmp2->next;
					delete tmp2;
					break;
				}
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
		}

	}
}

void List::displayList(){
	Node * tmp = head;
	while (tmp){
		std::cout <<tmp->data<<std::endl;
		tmp = tmp->next;
	}
}

List::~List() {
	Node * tmp = head;
	while (!isEmpty()){
		tmp = head;
		head = head->next;
		delete tmp;
		std::cout <<"A node was deleted."<<std::endl;
	}
}
