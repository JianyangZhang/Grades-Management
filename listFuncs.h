// Name: Jianyang Zhang
// Loginid: jianyanz
// CSCI 455 PA5
// Spring 2016


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

//insert a node into the front, return true if insert successfully
bool listInsert(ListType & list, string key, int value);

//remove a node based on the key, return true if insert successfully, false if the key doesn't exist
bool listRemove(ListType & list, string key);

//update a node based on the key, return true if update successfully, false if the key doesn't exist
bool listUpdate(ListType & list, string key, int value);

//return the value of a key, if the key doesn't exist, return -1
int listRead(ListType list, string key);

//return the length of a given list
unsigned int listLength(ListType list);

//print all elements
void listPrint(ListType list);

// keep the following line at the end of the file
#endif
