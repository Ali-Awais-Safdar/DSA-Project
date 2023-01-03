#include "Hashtable.h"
#include "Parser1.h"

//void searchByDirector(string director, HashTableLinkedList& ht) {
//    // Convert the director's name to lowercase for case-insensitive comparison
//    for (char& c : director) {
//        c = tolower(c);
//    }
//    // Check if the hash table is empty
//    if (ht.use == 0) {
//        cout << "The hash table is empty." << endl;
//        return;
//    }
//    // Iterate through the hash table
//    for (int i = 0; i < ht.size; i++) {
//        if (ht.table[i] != nullptr) {
//            // Get the data for the entry at the current index
//            string showid = ht.table[i]->showid;
//            Template_LinkList* data = ht.table[i]->l1;
//            // Convert the director's name in the entry to lowercase for case-insensitive comparison
//            string entryDirector = data->get_data(1);
//            for (char& c : entryDirector) {
//                c = tolower(c);
//            }
//            // Check if the director matches the given name
//            if (entryDirector == director) {
//                // Print the show name
//                cout << data->get_data(2) << endl;
//            }
//        }
//    }
//}
//
//void searchByTitle(string title, HashTableLinkedList& ht) {
//    // Convert the title to lowercase for case-insensitive comparison
//    for (char& c : title) {
//        c = tolower(c);
//    }
//    // Check if the hash table is empty
//    if (ht.use == 0) {
//        cout << "The hash table is empty." << endl;
//        return;
//    }
//    // Iterate through the hash table
//    for (int i = 0; i < ht.size; i++) {
//        if (ht.table[i] != nullptr) {
//            // Get the data for the entry at the current index
//            string showid = ht.table[i]->showid;
//            Template_LinkList* data = ht.table[i]->l1;
//            // Convert the title in the entry to lowercase for case-insensitive comparison
//            string entryTitle = data->get_data(2);
//            for (char& c : entryTitle) {
//                c = tolower(c);
//            }
//            // Check if the title matches the given title
//            if (entryTitle == title) {
//                // Print the movie information
//                cout << "Title: " << data->get_data(2) << endl;
//                cout << "Release Year: " << data->get_data(3) << endl;
//                cout << "Rating: " << data->get_data(4) << endl;
//                cout << "Duration: " << data->get_data(5) << endl;
//                cout << "Actors: " << data->get_data(6) << endl;
//                cout << "Director: " << data->get_data(1) << endl;
//                cout << "Genre: " << data->get_data(7) << endl;
//                cout << "Description: " << data->get_data(8) << endl;
//            }
//        }
//    }
//}

int countCast(string title, HashTableLinkedList ht) {
    int key = ht.getKey(title);
    Template_LinkList* l1 = ht.table[key]->l1;
    string cast = l1->get_data(3);
    int count = 0;
    bool in_name = false;
    for (int i = 0; i < cast.size(); i++) {
        if (cast[i] == ',' || i == cast.size() - 1) {
            count++;
            in_name = false;
        }
        else if (!in_name && cast[i] != ' ') {
            in_name = true;
        }
    }
    return count;
}

bool areActorsInSameCast(string actor1, string actor2, HashTableLinkedList& table) {
    for (int i = 0; i < 8000; i++) {
        if (table.table[i] != nullptr) {
            if (table.table[i]->l1->get_data(3).find(actor1) != string::npos && table.table[i]->l1->get_data(3).find(actor2) != string::npos) {
                // Both actors were found in the cast of the same show
                return true;
            }
        }
    }
    // Actors were not found in the same cast
    return false;
}

void printTitlesByDirector(const std::string& director, HashTableLinkedList& table) {
    // Check if the hash table is empty
    if (table.use == 0) {
        cout << "The hash table is empty." << endl;
        return;
    }

    bool found = false;
    // Iterate through all the entries in the hash table
    for (int i = 0; i < table.size; i++) {
        if (table.table[i] != nullptr) {
            // Check if the director name in the current entry matches the given director name
            if (table.table[i]->l1->get_data(2) == director) {
                // Print the title of the show
                cout << table.table[i]->l1->get_data(1) << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No shows found for director: " << director << endl;
    }
    else {
        cout << "was found for director: " << director << endl;
    }
}

void printShowInfo(const std::string& title, HashTableLinkedList& table) {
    // Check if the hash table is empty
    if (table.use == 0) {
        cout << "The hash table is empty." << endl;
        return;
    }
    bool found = false;
    // Iterate through all the entries in the hash table
    for (int i = 0; i < table.size; i++) {
        if (table.table[i] != nullptr) {
            // Check if the title in the current entry matches the given title
            if (table.table[i]->l1->get_data(1) == title) {
                // Print the show information
                std::cout << "Title: " << table.table[i]->l1->get_data(1) << std::endl;
                std::cout << "Director: " << table.table[i]->l1->get_data(2) << std::endl;
                std::cout << "Country: " << table.table[i]->l1->get_data(4) << std::endl;
                std::cout << "Date Added: " << table.table[i]->l1->get_data(5) << std::endl;
                std::cout << "Release Year: " << table.table[i]->l1->get_data(6) << std::endl;
                std::cout << "Rating: " << table.table[i]->l1->get_data(7) << std::endl;
                std::cout << "Duration: " << table.table[i]->l1->get_data(8) << std::endl;
            }
        }
    }
}



int main() {
	Parse();
	HashTableLinkedList h1(content);
	//h1.search("s1");
    
    /*string title = "Bobby";
	int count = countCast(title,h1);
	cout << "The number of cast members in " << title << " is " << count << endl;*/

    /*bool sameCast = areActorsInSameCast("Will Arnett", "Aaron Paul", h1);
    if (sameCast) {
        cout << "Actors are in the same cast." << endl;
    }
    else {
        cout << "Actors are not in the same cast." << endl;
    }*/
    
	//printTitlesByDirector("Siddique", h1);
    
    //printShowInfo("Boss", h1);
    

    
    
    
    
    

    

    
    
	
    
    
    
    
    
    
    
    return 0;
}


