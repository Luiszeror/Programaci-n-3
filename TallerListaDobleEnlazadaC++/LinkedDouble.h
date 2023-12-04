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
    void addNodeFirst();
    void addNodeLast();
    vector<T> getList();
    virtual ~LinkedDouble();

private:

    Node<T>* head;
    Node<T>* last;

};




#endif //TALLERLISTADOBLEENLAZADAC___LINKEDDOUBLE_H
