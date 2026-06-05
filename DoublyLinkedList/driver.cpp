#include "DoublyLinkedList.h"
#include <string>

int main(int argc, char *args[]) 
{
    DoublyLinkedList<std::string> bands;

    std::cout << "\nHow many items are in the list? " << bands.getSize() << "\n\n";

    std::cout << "*Populating list with bands*\n\n";

    bands.pushBack("Belmont");
    bands.pushFront("The Starting Line");
    bands.pushFront("Blink 182");
    bands.pushFront("The Story So Far");
    bands.pushBack("Underbrook");

    bands.printForward();
    bands.printBackward();

    std::cout << "\nHow many items are in the list? " << bands.getSize() << "\n\n";
    std::cout << "Does Sum 41 exist in the list? " << (bands.exists("Sum 41") ? "Yes\n" : "No\n");
    std::cout << "Does Underbrook exist in the list? " << (bands.exists("Underbrook") ? "Yes\n\n" : "no\n\n");

    std::cout << "*Clearing list*\n\n";

    bands.clear();

    std::cout << "How many items are in the list? " << bands.getSize();
    
    return 0;
}