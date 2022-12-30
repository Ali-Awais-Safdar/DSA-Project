#pragma once
#include <iostream>
#include <string>
#include "Parser.h"

using namespace std;


class Template_Node {
public:
	string data;
	Template_Node* next;
	Template_Node* prev;
	Template_Node() {
		data = ' ';
		next = nullptr;
		prev = nullptr;
	}
};

class Template_LinkList {
public:
	Template_Node* loc;
	Template_Node* ploc;
	Template_Node* first;
	Template_Node* last;
	Template_LinkList() {
		loc = NULL;
		ploc = NULL;
		first = NULL;
		last = NULL;
	}
	~Template_LinkList(){

	}
	bool is_empty() {
		if (first == NULL and last==NULL) {
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
	void insert_node(Template_Node* a) {
		if (is_empty()) {
			first = a;
			last = first;
		}
		else {
			last->next = a;
			a->prev = last;
			last = a;
			loc = last;
		}
	}
	void print_data() {
		loc = first;
		while (!is_empty() and loc!=NULL) {
			cout << loc->data <<endl;
			loc = loc->next;
		}
		if (is_empty()) {
			cout << "err";
		}
	}
};
