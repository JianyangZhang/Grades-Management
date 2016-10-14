// Name: Jianyang Zhang
// Loginid: jianyanz
// CSCI 455 PA5
// Spring 2016


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}

//*************************************************************************
// put the function definitions for your list functions below

//insert a node into the front, return true if insert successfully
bool listInsert(ListType & list, string key, int value){
	list = new Node(key, value, list);
	return true;
}

//remove a node based on the key, return true if insert successfully, false if the key doesn't exist
bool listRemove(ListType & list, string key){
	if(list == NULL){
		return false; 
	}
		
	//if the first Node is the target
	if(list->key == key){
		Node * deadGuy = list;
		list = list->next;
		delete deadGuy;
		return true;
	}
	
	//if the first Node is not the target
	Node * iterator = list;	
	while(iterator->next != NULL){		
		if(iterator->next->key == key){	
			Node * deadGuy = iterator->next;		
			iterator->next = deadGuy->next;
			delete deadGuy;
			return true;
		}
		iterator = iterator->next;
	}
	return false;
}

//update a node based on the key, return true if update successfully, false if the key doesn't exist
bool listUpdate(ListType & list, string key, int value){
	Node * iterator = list;
	while(iterator != NULL){
		if(iterator->key == key){
			iterator->value = value;
			return true;
		}
		iterator = iterator->next;	
	}
	return false;
}

//return the value of a key, if the key doesn't exist, return -1
int listRead(ListType list, string key){
	while(list != NULL){
		if(list->key == key){
			return list->value;
		}
		list = list->next;
	}
	return -1;
}

//return the length of a given list
unsigned int listLength(ListType list){
	unsigned int length = 0;
	while(list != NULL){
		length++;
		list = list->next;
	}
	return length;
}

//print all elements
void listPrint(ListType list){
	if(list == NULL){
		return;
	}
	
	cout << list->key << "\t\t" << list->value << endl;

	while(list->next != NULL){
		cout << list->next->key << "\t\t" << list->next->value << endl;
		list = list->next;
	}
}


