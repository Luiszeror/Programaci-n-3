//
// Created by SALA 8 on 15/11/2023.
//

#ifndef PRJDATASTRUCTURED_LINKEDLIST_H
#define PRJDATASTRUCTURED_LINKEDLIST_H

#include <vector>
#include "Node.h"

template <class T>

class LinkedList {

public:

    LinkedList();

    bool isEmpty();

    void addNodeFirst(T info);

    std :: vector<T> getLinkedList();

    virtual ~LinkedList();


private:

    Node<T> *head;

};



#endif //PRJDATASTRUCTURED_LINKEDLIST_H
