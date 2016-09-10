/**
*       @file DoubleLinkedList.cpp
*       @author Brad Gibbons
*       @date 2016.09.09
*       Purpose: Implementation of the DoubleLinkedList class
*/

#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
	while (m_size > 0) {
		removeFront();
	}
}

int DoubleLinkedList::size() const {
	return(m_size);
}

void DoubleLinkedList::pushFront(int year, int month, int day) {
	if (m_size == 0) { //If no Nodes have been added
		Node* temp = new Node();
		//Set values for the new Node
		temp->setYear(year);
		temp->setMonth(month);
		temp->setDay(day);
		//Point m_front and m_back
		m_front = temp;
		m_back = m_front;
	} else { //If one or more Nodes have been added already
		Node* temp = new Node();
		//Set values for the new Node
		temp->setYear(year);
		temp->setMonth(month);
		temp->setDay(day);
		//Point the new Node and previous m_front to each other
		temp->setNext(m_front);
		m_front->setPrev(temp);
		//Set m_front as the new Node
		m_front = temp;
	}
	m_size++; //Increment size
}

void DoubleLinkedList::removeFront() {
	if (m_size == 1) { //If only one Node in the DoubleLinkedList
		delete m_front;
		m_front = nullptr;
		m_back = nullptr;
	} else { //If there is more than one Node
		Node* temp = m_front->getNext(); //Get the second Node in the list
		temp->setPrev(nullptr); //Point that Node to nullptr
		delete m_front; //Delete the front Node
		m_front = temp; //Point m_front to the second Node
	}
	m_size--; //Decriment size
}

Node* DoubleLinkedList::getFront() const {
	return(m_front);
}

Node* DoubleLinkedList::getBack() const {
	return(m_back);
}