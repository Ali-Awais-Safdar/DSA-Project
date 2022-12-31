#pragma once
#include <iostream>
#include <string>
#include "TemplateLinklist.h"

using namespace std;

class arraytemplate :public Template_LinkList {
public:
	int index = 0;
	void insert(string value) {
		if (is_empty()) {
			Template_Node* nn = new Template_Node();
			nn->data = value;
			first = nn;
			last = first;
		}
		else {
			Template_Node* nn = new Template_Node();
			nn->data = value;
			loc->next = nn;
			nn->prev = loc;
			loc = nn;
			last = loc;
			loc->prev = ploc;
		}
	}
};