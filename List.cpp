/*
 * List.cpp
 *
 *  Created on: 15 sept. 2020
 *      Author: Usuario
 */
 
#include <iostream>
using namespace std;
#include "List.h"

List::List() {
	head = NULL;
}

bool List::isEmpty(){
	return head == NULL;
}

void List::addNode(int data){
	Node * tmp = new Node();
	tmp->data = data;
	tmp->next = head;
	head = tmp;

}

void List::deleteNode(int data){
	Node * tmp2 = head;
	if (tmp2 != NULL){
		if (tmp2->data == data){
			head = tmp2->next;
			delete tmp2;
		}else{
			Node * tmp = tmp2;
			while(tmp2 != NULL){
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
	while (tmp != NULL){
		cout <<tmp->data<<endl;
		tmp = tmp->next;
	}
}

List::~List() {
	Node * tmp = head;
	while (!isEmpty()){
		tmp = head;
		head = head->next;
		delete tmp;
		cout <<"A node was deleted."<<endl;
	}
}

