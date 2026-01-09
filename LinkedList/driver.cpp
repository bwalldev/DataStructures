// driver.cpp
// A simple driver program to test the LinkedList class

#include "LinkedList.h"
#include <iostream>

int main(int argc, char* argv[]) {
    LinkedList<int> myList;

    std::cout << "Link List Created.\n\n";

    std::cout << "Adding 10, 20, 30 to the list in that order.\n";

    // Adding integer elements to the list. 
    myList.append(10);
    myList.append(20);
    myList.append(30);
    
    // Displaying the list
    myList.print();

    std::cout << "Checking the size of the list.\n";
    std::cout << "Linked list size: " << myList.length() << " elements\n\n";

    std::cout << "Adding 40, 50, 60 to the list in that order.\n";

    // Adding more elements to the list
    myList.append(40);
    myList.append(50);
    myList.append(60);

    // Displaying the list
    myList.print();

    std::cout << "Remvoing an element from the list.\n";

    // Removing an element from the end of the list
    myList.pop();

    // Displaying the list
    myList.print();

    std::cout << "Clearing the list.\n";
    myList.clear();
    myList.print();

    return 0;
}