#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "TemplateLinklist.h"
using namespace std;

int GetLine2() {
    // Open the file
    fstream file("filename.csv");

    Template_LinkList linklist;
    // Read each line of the file
    string line;
    while (getline(file, line)) {
        // Split the line into cells
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ';')) {
            linklist.insert_data(cell);
        }
    }

    linklist.print_data();
    return 0;
}