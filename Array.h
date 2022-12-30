#pragma once
#include <iostream>
#include <string>
#include "TemplateLinklist.h"
#include "Parser.h"
#include "PointerLinklists.h"

using namespace std;

class Array_Pointing_To_Linklist: public Template_LinkList {
	int size = 0;
	Template_Linklist* Array = new Template_LinkList();
};