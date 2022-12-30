#pragma once
#include <iostream>
#include <string>
#include "TemplateLinklist.h"
#include "Parser.h"


class Pointer_LinkList :  public Template_LinkList {
public:
	void insert_column(string a) {
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
};