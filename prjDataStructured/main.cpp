#include <iostream>


#include "Dish.h"
#include "LinkedList.cpp"

using namespace std;

int main() {

    LinkedList<char> *linkedList = new LinkedList<char>();

    linkedList->addNodeFirst('L');
    linkedList->addNodeFirst('u');
    linkedList->addNodeFirst('i');
    linkedList->addNodeFirst('s');
    linkedList->addNodeFirst('_');
    linkedList->addNodeFirst('E');
    linkedList->addNodeFirst('s');
    linkedList->addNodeFirst('t');
    linkedList->addNodeFirst('e');
    linkedList->addNodeFirst('b');
    linkedList->addNodeFirst('a');
    linkedList->addNodeFirst('n');



    for(int i= size(linkedList->getLinkedList());i>-1;i--){

        std:: cout << linkedList->getLinkedList()[i];
    }

    delete(linkedList);

    return 0;
}
