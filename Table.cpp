// Name: Jianyang Zhang
// Loginid: jianyanz
// CSCI 455 PA5
// Spring 2016

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table(){
	numOfEntries = 0;
	hashSize = HASH_SIZE; 
	data = new ListType[hashSize];
	for(unsigned int i = 0; i < hashSize; i++){
		data[i] = NULL;
	}
}


Table::Table(unsigned int hSize){
	numOfEntries = 0;
	hashSize = hSize;
	data = new ListType[hashSize];
	for(unsigned int i = 0; i < hashSize; i++){
		data[i] = NULL;
	}
}

// lookup the value of a given key, return a pointer to this value
// if the key isn't present, return a null pointer
int * Table::lookup(const string &key){
	for(unsigned int i = 0; i < hashSize; i++){
		Node * iterator = data[i];
		while(iterator != NULL){			
			if(iterator->key == key){
				return &(iterator->value);
			}
			iterator = iterator->next;
		}
	}
	return NULL;	
}

// remove an entry by its key, return false if the key isn't present 
bool Table::remove(const string &key){
	for(unsigned int i = 0; i < hashSize; i++){
		if(listRemove(data[i], key)){
			numOfEntries--;
			return true;
		}
	}
	return false;
}

// insert a key and its value into this table
// if the key was already present, don't do the insert and return false 
bool Table::insert(const string &key, int value){
	if(lookup(key) == NULL){
		unsigned int index = hashCode(key);
		listInsert(data[index], key, value);	
		numOfEntries++;	
		return true;
	}
	return false;
}

// return the number of entries
int Table::numEntries() const{
	return numOfEntries;
}

// print all entries
void Table::printAll() const{
	for(unsigned int i = 0; i < hashSize; i++){
		listPrint(data[i]);	
	}
}

// print out statistics about this table
void Table::hashStats(ostream &out) const{
	out << "number of buckets: " << hashSize << endl;
	out << "number of entries: " << numOfEntries << endl;
	out << "number of non-empty buckets: " << occupiedBucket() <<endl;
	out << "longest chain: " << longestChain() << endl;
	out << "cmd>";
}


// add definitions for your private methods here

// return the number of non-empty buckets
unsigned int Table::occupiedBucket() const{
	unsigned int counter = 0;
	for(unsigned int i = 0; i < hashSize; i++){
		if(data[i] != NULL){
			counter++;
		}
	}
	return counter;
}

// return the length of the longest chain
unsigned int Table::longestChain() const{
	unsigned int longestSoFar = 0;
	for(unsigned int i = 0; i < hashSize; i++){
		unsigned int currentLength = listLength(data[i]);
		if(currentLength > longestSoFar){
			longestSoFar = currentLength;
		}
	}
	return longestSoFar;
}

