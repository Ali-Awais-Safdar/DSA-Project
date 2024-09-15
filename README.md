# Data Structures and Algorithms Project

This project implements a custom hash table with linked lists to store and manage data from a dataset. The hash table uses quadratic probing for collision resolution, and the project incorporates efficient data storage and retrieval techniques. The dataset is parsed from a CSV file and stored in a hash table where various operations can be performed, such as searching for show details, counting cast members, and printing show information by director.

## Features

- **2D Array**: Used for storing tuples in a segmented manner.
- **Hash Table**: Implements quadratic probing and stores hashed data in linked nodes.
- **Linked List**: Stores detailed information about each entry from the dataset.
- **Custom Hash Function**: Calculates keys for the hash table based on the ASCII values of show IDs.

## Files

- **Hash.h**: Implements the hash table using linked lists for storing data and includes functions for inserting and searching data.
- **Template_Linklist.h**: Implements a doubly linked list to store detailed information for each data entry.
- **Parser1.h**: Parses the input CSV file (`Netflix.csv`) and stores the data in a 2D array.
- **Source.cpp**: Contains the main logic, including functions to:
  - Check if two actors are in the same cast.
  - Count the number of cast members for a given show.
  - Print titles by a specific director.
  - Display information about a show.

## Key Functions

1. **insertIntoTable()**: Inserts a tuple into the hash table based on the show's unique ID.
2. **getKey()**: Generates a hash key by summing the ASCII values of characters in the show ID and performing modulo operation.
3. **search()**: Retrieves and displays the details of a show based on the show ID.
4. **printTitlesByDirector()**: Displays all the titles directed by a specific director.
5. **areActorsInSameCast()**: Determines if two actors appeared in the same show.
6. **countCast()**: Counts the number of cast members in a show.
7. **printShowInfo()**: Prints the full details of a show, including title, director, country, release year, and more.

## How to Run

1. Clone the repository or download the source code.
2. Ensure that you have the `Netflix.csv` dataset in the project directory.
3. Compile the project using a C++ compiler.
4. Run the program and use the available functions to interact with the data.

## Data Parsing

The project uses a custom CSV parser in `Parser1.h` to read the `Netflix.csv` file. The data is stored in a 2D array, which is then used to populate the hash table for efficient access.

## Acknowledgments

This project demonstrates the use of advanced data structures such as hash tables, linked lists, and 2D arrays. It also applies algorithms for efficient data retrieval and manipulation.

