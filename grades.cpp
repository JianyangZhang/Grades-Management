// Name: Jianyang Zhang
// Loginid: jianyanz
// CSCI 455 PA5
// Spring 2016

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"
#include <sstream>
// cstdlib needed for call to atoi
#include <cstdlib>

// print out a brief command summary 
void showHelp();

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

	int hashSize = Table::HASH_SIZE;

	Table * grades; // Table is dynamically allocated below, so we can call
                	// different constructors depending on input from the user.

	if (argc > 1) {
		
		hashSize = atoi(argv[1]);  // atoi converts c-string to int

		if (hashSize < 1) {
			cout << "Command line argument (hashSize) must be a positive number" << endl;
			return 1;
		}

		grades = new Table(hashSize);
	
	}else { // no command line args given -- use default table size
		
		grades = new Table();
		
	}


	grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*
  

    bool keepgoing = true;
	string command;
	
    while(keepgoing){ 
    
    	// split the command by space, and store them into an array of strings
    	string args[3]; 
		getline(cin, command); 		
		int commandFlag = 0;
		int argsIndex = 0;
		command = command + " "; 
		while(argsIndex < 3){
			commandFlag = command.find(" ");
			for(int i = 0; i < commandFlag; i++){
				args[argsIndex] += command[i]; 				
			}			
			command.erase(0,commandFlag+1);
			argsIndex++;
		}
		
		// match the arguments
		if(args[0] == "insert"){			
			if(args[1] != "" && args[2] != ""){
				if(!grades->insert(args[1],atoi(args[2].c_str()))){
					cout << "Insert Failed: this name was already present!" << endl;
				}
			}else{
				cout << "Error: lack of argument." << endl;
				showHelp();
			}
			cout << "cmd>";				
		}else if(args[0] == "change"){
			if(args[1] != "" && args[2] != ""){
				int * target = grades->lookup(args[1]);
				if(target == NULL){
					cout << "Change Failed: this name isn't present!" << endl; 
				}else{
					*target =  atoi(args[2].c_str());
				}
			}else{
				cout << "Error: lack of argument." << endl;
				showHelp();
			}
			cout << "cmd>";			
		}else if(args[0] == "lookup"){
			if(args[1] != ""){
				int * target = grades->lookup(args[1]);
				if(target == NULL){
					cout << "Lookup Failed: this name isn't present!" << endl; 
				}else{
					cout << "Name: " << args[1] << "\tScore: " << *target << endl;
				}
			}else{
				cout << "Error: lack of argument." << endl;
				showHelp();
			}
			cout << "cmd>";	
		}else if(args[0] == "remove"){
			if(args[1] != ""){
				if(!grades->remove(args[1])){
					cout << "Remove Failed: this name isn't present!" << endl;
				}
			}else{
				cout << "Error: lack of argument." << endl;
				showHelp();
			}
			cout << "cmd>";			
		}else if(args[0] == "print"){
			grades->printAll();
			cout << "cmd>";
		}else if(args[0] == "size"){
			cout << grades->numEntries() << endl;
			cout << "cmd>";
		}else if(args[0] == "stats"){
			grades->hashStats(cout);
		}else if(args[0] == "help"){
			showHelp();
			cout << "cmd>";
		}else if(args[0] == "quit"){
			keepgoing = false;
		}else{
			cout << "Error: invalid command." << endl;
			showHelp();
			cout << "cmd>";
		}
				        
	}	
  return 0;
}

// print out a brief command summary 
void showHelp(){
	cout << "" << endl;
	cout << "Valid Commands Summary:" << endl;
	cout << "" << endl;
	cout << "insert <name> <score>\t\tInsert this name and score into this grade table." << endl;
	cout << "change <name> <newscore>\tChange the score for this name." << endl; 
	cout << "lookup <name>\t\t\tLookup this name, and print out his or her score." << endl;
	cout << "remove <name>\t\t\tRemove this student." << endl;
	cout << "print\t\t\t\tPrints out all names and scores in this grade table." << endl;
	cout << "size\t\t\t\tPrints out the number of entries in this grade table." << endl;
	cout << "stats\t\t\t\tPrints out statistics about this grade table." << endl;
	cout << "help\t\t\t\tPrints out a brief command summary." << endl;  
	cout << "quit\t\t\t\tExits the program." << endl; 
	cout << "" << endl;
}


