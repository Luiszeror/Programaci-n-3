//
// Created by Esteban on 3/12/2023.
//

#include <iostream>
#include "LinkedDouble.h"

template<class T>
LinkedDouble<T>::~LinkedDouble() {


}

template<class T>
vector<T> LinkedDouble<T>::getList(bool reverse) {
    std::vector<T> out;
    Node<T>* aux = reverse ? head : last;
    while( aux != NULL ){
        out.push_back( aux->info );
        aux = reverse ? aux->next : aux->previous;
    }
    return out;
}

template<class T>
void LinkedDouble<T>::addAfterTo(Node<T>* targetNode, T info) {
    if (targetNode == nullptr) {
        std::cout << "Error: El nodo objetivo es nulo." << std::endl;
        return;
    }
    Node<T>* newNode = new Node<T>(info);

    if (isEmpty()) {
        head = newNode;
        last = newNode;
    } else {
        newNode->next = targetNode->next;
        newNode->previous = targetNode;

        if (targetNode->next != nullptr) {
            targetNode->next->previous = newNode;
        } else {
            last = newNode;
        }
        targetNode->next = newNode;
    }
}


template<class T>
void LinkedDouble<T>::addNodeLast(T info) {

    Node<T>* newNode = new Node<T>(info);
    if ( isEmpty( ) ){
        head = newNode;
        last = newNode;
    }else{
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
    }

}

template<class T>
void LinkedDouble<T>::addNodeFirst(T info) {

    if(isEmpty()){

        head = last = new Node<T>(info);
    }else{

        Node<T> *newNode = new Node<T>(info);

        newNode->next=head;
        head->previous = newNode;
        head = newNode;
    }

}

template <class T>
void LinkedDouble<T>::addNodeBeforeTo(Node<T>* targetNode, T info) {
    if (targetNode == nullptr) {
        std::cout << "Error: El nodo objetivo es nulo." << std::endl;
        return;
    }

    Node<T>* newNode = new Node<T>(info);

    if (isEmpty()) {
        head = newNode;
        last = newNode;
    } else {
        if (targetNode->previous != nullptr) {
            targetNode->previous->next = newNode;
            newNode->previous = targetNode->previous;
        } else {
            head = newNode;
        }

        newNode->next = targetNode;
        targetNode->previous = newNode;
    }
}

template <class T>
void LinkedDouble<T>::addNodeSorted(T info) {
    Node<T>* newNode = new Node<T>(info);

    if (isEmpty() || info.getId() < head->info.getId()) {
        addNodeFirst(info);
        return;
    }

    Node<T>* current = head;
    while (current->next != nullptr && current->next->info.getId() < info.getId()) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->previous = current;

    if (current->next != nullptr) {
        current->next->previous = newNode;
    } else {
        last = newNode;
    }

    current->next = newNode;
}
template<class T>
Node<T> *LinkedDouble<T>::findNode(std::string criteria) {
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->info.getId() == criteria) {
            return current;
        }

        current = current->next;
    }
    return nullptr;
}

template<class T>
T *LinkedDouble<T>::findInfo(const std::string &id) {
    Node<T> *aux = head;

    while(aux != NULL){

        if(aux->info.getId().compare(id)==0){


            return &aux->info;
        }

        aux = aux->next;
    }

    return NULL;
}


template<class T>
int LinkedDouble<T>::getSize()  {
    int count = 0;
    Node<T>* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}



template<class T>
T LinkedDouble<T>::getFirst() {
    if (head != nullptr) {
        return head->info;
    } else {

        return T();
    }
}

template<class T>
T LinkedDouble<T>::getLast(){
    if (last != nullptr) {
        return last->info;
    } else {
        return T();
    }
}

template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
LinkedDouble<T>::LinkedDouble() {

    head = NULL;
    last = NULL;

}
template<class T>
T LinkedDouble<T>::getObjectById(const std::string& id) {
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->info.getId() == id) {
            return current->info;
        }
        current = current->next;
    }

    throw std::runtime_error("Error: Objeto no encontrado con el ID especificado.");
}

template<class T>
void LinkedDouble<T>::deleteNodeById(const std::string& id) {
    Node<T>* targetNode = findNode(id);

    if (targetNode != nullptr) {
        Node<T>* previousNode = targetNode->previous;
        Node<T>* nextNode = targetNode->next;

        if (previousNode != nullptr) {
            previousNode->next = nextNode;
        } else {
            head = nextNode;
        }

        if (nextNode != nullptr) {
            nextNode->previous = previousNode;
        } else {
            last = previousNode;
        }

        delete targetNode;
    } else {
        throw std::runtime_error("Error: Objeto no encontrado con el ID especificado.");
    }
}
