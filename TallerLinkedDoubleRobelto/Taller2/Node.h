//
// Created by Esteban on 3/12/2023.
//

#ifndef TALLERLISTADOBLEENLAZADAC___NODE_H
#define TALLERLISTADOBLEENLAZADAC___NODE_H

#include <cstdlib>

template <class T>class LinkedDouble;

template <class T>
class Node {

    friend class LinkedDouble<T>;

public:

    Node(){
        next = NULL;
        previous = NULL;
    }

    Node(T info) : info(info) {
        next = NULL;
        previous = NULL;
    }

    virtual ~Node();

private:

    T info;
    Node<T>* next;
    Node<T>* previous;


};

template<class T>
Node<T>::~Node() {

}


#endif //TALLERLISTADOBLEENLAZADAC___NODE_H
