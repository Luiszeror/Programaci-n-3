//
// Created by SALA 8 on 15/11/2023.
//

#include "LinkedList.h"

template <class T>

        LinkedList<T> :: LinkedList() {

            LinkedList :: head= NULL;
        }

template<class T>

        bool LinkedList<T>::isEmpty() {

            return head == NULL;
        }

template<class T>

        void LinkedList<T>::addNodeFirst(T info) {

           if(isEmpty()){

               head=new Node<T>(info);

           }else{

               Node<T> *nuevo = new Node<T>(info);
               nuevo->next= head;
               head= nuevo;
           }

        }

template<class T>

        std::vector<T> LinkedList<T>::getLinkedList() {
             std :: vector<T> linked;
             Node<T> *aux= head;

             while(aux !=NULL){
                 linked.push_back( aux->info );
                 aux= aux->next;
             }

             return linked;
        }

template<class T>

        LinkedList<T>::~LinkedList() {

        }