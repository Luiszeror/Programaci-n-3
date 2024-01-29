//
// Created by Esteban on 24/11/2023.
//

#ifndef PRJDATASTRUCTURED_LINKEDLISTLIST_H
#define PRJDATASTRUCTURED_LINKEDLISTLIST_H

#include <string>
#include <vector>
#include "Node.h"



template <class T>

class LinkedListList {

public:

    LinkedListList();
    bool isEmpty();
    void addNodeFirst(T info);
    void addNodeLast(T info);
    void addNodeAfterTo(Node <T>*,T info);
    void addNodeBeforeTo(Node<T>*, T info);
    void addNodeSorted(T info);
    Node<T>* findNode(std::string);
    std :: vector<T> getLinkedListLIst(bool);
    T* deleteNode(Node<T>*);
    int getSize();
    T* getObject(int);
    T* getFirst();
    T* getLast();
    virtual ~LinkedListList();

private:

    Node<T> *head;

};




#endif //PRJDATASTRUCTURED_LINKEDLISTLIST_H
