//
// Created by Esteban on 3/12/2023.
//

#ifndef TALLERLISTADOBLEENLAZADAC___LINKEDDOUBLE_H
#define TALLERLISTADOBLEENLAZADAC___LINKEDDOUBLE_H

#include <vector>
#include "Node.h"

using namespace std;


template <class T>

class LinkedDouble {


public:

    LinkedDouble();
    bool isEmpty();
    void addNodeFirst(T);
    void addNodeLast(T);
    vector<T> getList(bool);
    void addAfterTo(Node<T>* targetNode, T );
    void addNodeBeforeTo(Node<T>* targetNode, T );
    void addNodeSorted(T);
    Node<T>* findNode( std::string);
    T* findInfo(const std::string& criteria);
    int getSize();
    T getFirst();
    T getLast();
    T getObjectById(const std::string& id);
    void deleteNodeById(const std::string& id);
    virtual ~LinkedDouble();

private:

    Node<T>* head;
    Node<T>* last;

};



#endif //TALLERLISTADOBLEENLAZADAC___LINKEDDOUBLE_H
