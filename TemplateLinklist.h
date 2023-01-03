#pragma once
//#include <iostream>
//#include <string>
//#include "Parser.h"
#include <iostream>

using namespace std;


class Template_Node {
public:
	
	string data;
	Template_Node* next;
	Template_Node* prev;
	
};

class Template_LinkList {
public:
	Template_Node* loc;
	Template_Node* ploc;
	Template_Node* first;
	Template_Node* last;
	Template_LinkList(int index, string** content) {  //function takes in a 2d array and stores the tuple at a given index into a linked list.
		for (int i = 1; i < 12; i++) {
			insert_data(content[index][i]); 
		}
	}
	~Template_LinkList() {

	}
	bool is_empty() {
		if (first == nullptr and last == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void insert_data(string a) {
		Template_Node* nn = new Template_Node();
		nn->data = a;
		if (is_empty()) {
			nn->next = nullptr;
			nn->prev = nullptr;
			first = nn;
			last = first;
		}
		else {
			last->next = nn;
			nn->prev = last;
			last = nn;
			loc = last;
		}
	}
	
	
	string get_data(int index) {
		Template_Node* current = first;
		// Iterate to the node at the given index
		for (int i = 0; i < index; i++) {
			current = current->next;
			if (current == nullptr) {
				// Return an empty string if the index is out of range
				return "";
			}
		}
		// Return the data at the node
		return current->data;
	}

	
	void print_data() {
		loc = first;	
		while (!is_empty() and loc != nullptr) {
			cout << loc->data << endl;
			loc = loc->next;
		}
		if (is_empty()) {
			cout << "err";
		}
	}
};

class Node_Hash {
public:
	string showid;
	Template_LinkList* l1;
};