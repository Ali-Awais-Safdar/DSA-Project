#pragma once
#include "TemplateLinklist.h"


class HashTableLinkedList {
public:
    const int size = 8000;
    int use = 0;
    Node_Hash **table = new Node_Hash*[size]; // table points towards a node which points towards a data entry in the hash table
    HashTableLinkedList(string **array);
	void insertIntoTable(int index,string showid, string** content);
    int getKey(string showID);
    void search(string showid);
    int countCast(string showid);
};

HashTableLinkedList::HashTableLinkedList(string **array) { //constructs a null hash table of 8000 indexes and inserts data acoording to the dataset

    for (int i = 0; i < 8000; i++) {
        table[i] = nullptr;
    }
	for (int i = 0; i < 5650; i++) {
		insertIntoTable(i,array[i][0],array);
	}
    
}

void HashTableLinkedList::insertIntoTable(int index,string showid, string** content) { //takes showid from the 2d array and generates a key for a tuple

	int key = getKey(showid);
    if (table[key] != nullptr) {
        int i = 1;
        while (table[key] != nullptr) {
            key = (getKey(showid) + i * i)%size;
            i++;
            if (use == size) {
                break;
            }
        }
    }
	Node_Hash* nn = new Node_Hash(); // stores the data associated with a show id in a linked list
	nn->showid = showid;
	nn->l1 = new Template_LinkList(index,content);
    // Check for an empty string in the director's name field
    //if (nn->l1->get_data(4).empty()) {
    //    nn->l1->get_data(4) = "Unknown";
    //}
    //if (nn->l1->get_data(3).empty()) {
    //    nn->l1->get_data(3) = "Unknown";
    //}
    table[key] = nn;
    use++;
    

}

int HashTableLinkedList::getKey(string showid) {
    // Add up the ASCII values of all the characters in the show ID
    int sum = 0;
	for (char c : showid) {
        sum += (int)c;
    }
    // Return the sum modulo the table size to get the key
    return sum % size;
}


void HashTableLinkedList::search(string showid) {
    int idx = 0;
	idx = getKey(showid);
	cout << table[idx]->showid << endl; // displays the showid at a particular key, then traverses the list to which the node is pointing and prints its data.
	table[idx]->l1->print_data();
}

