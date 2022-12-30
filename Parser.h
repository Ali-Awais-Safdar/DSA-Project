#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "TemplateLinklist.h"
#include "PointerLinklists.h"
using namespace std;

string GetLine() {
    // Open the Excel file
    ifstream file("NetFlix.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return " ";
    }

    const char DELIMITER = ',';
    Template_LinkList linklist;
    string line;
    bool quote_open = false;
    int count = 0;
    Pointer_LinkList linkedtitles;

    // Read each line from the file
    while (getline(file, line))
    {
        stringstream linestream(line);
        string attribute;
        while (getline(linestream, attribute, DELIMITER))
        {   
            if (count < 12) {
                linkedtitles.insert_column(attribute);
                count += 1;
            }
            if (attribute.length() > 0) {
                // Add the line to the string
                linklist.insert_data(attribute);
            }
        }
    }

    linklist.print_data();

    return " ";
}