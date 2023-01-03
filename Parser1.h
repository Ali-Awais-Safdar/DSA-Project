#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<string>> _content;
string** content = new string*[5650];

enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

vector<string> readCSVRow(const string& row) {
    CSVState state = CSVState::UnquotedField;
    vector<string> fields{ "" };
    size_t i = 0;
    for (char c : row) {
        switch (state) {
        case CSVState::UnquotedField:
            switch (c) {
            case ',':
                fields.push_back(""); i++;
                break;
            case '"': state = CSVState::QuotedField;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedField:
            switch (c) {
            case '"': state = CSVState::QuotedQuote;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedQuote:
            switch (c) {
            case ',':
                fields.push_back(""); i++;
                state = CSVState::UnquotedField;
                break;
            case '"':
                fields[i].push_back('"');
                state = CSVState::QuotedField;
                break;
            default:
                state = CSVState::UnquotedField;
                break;
            }
            break;
        }
    }
    return fields;
}

vector<vector<string>> readCSV(istream& in) {
    vector<vector<string>> table;
    string row;
    int counter = 0;
    while (getline(in, row)) {
        if (in.bad() || in.fail()) {
            break;
        }
        auto fields = readCSVRow(row);
        if (!fields.empty()) {
            table.push_back(fields);
            counter++;
        }
    }   
    return table;
}


void Parse() {
    ifstream infile("Netflix.csv");
    _content = readCSV(infile);
    for (int i = 0; i < 5650; i++) {
        content[i] = new string[12];
        for (int j = 0; j < 12; j++) {
            content[i][j] = _content[i][j];
        }
    }
    _content.clear();
}

#endif
