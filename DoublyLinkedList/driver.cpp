#include "DoublyLinkedList.h"
#include <string>

int main(int argc, char *args[]) 
{
    DoublyLinkedList<std::string> bands;

    bands.pushBack("Belmont");
    bands.pushFront("The Starting Line");
    bands.pushFront("Blink 182");
    bands.pushFront("The Story So Far");
    bands.pushBack("Underbrook");

    bands.printForward();
    bands.printBackward();
    
    return 0;
}