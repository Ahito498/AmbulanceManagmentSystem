//
// Created by Rashwan's on 01/12/2024.
//
#pragma once
#include "LinkedQueue.h"



//Cancellable queue using ID of the Patient derived from the linked queue class
template <typename T>
class cancellableQueue : public LinkedQueue<T> {
public:
    bool cancelRequest(int PatientID) {
        //create to pointers to node to link the prevous linked list related to the deleted one with the front element related to the deleted one
        Node<T>* prev = nullptr;
        Node<T>* curr = this->getFront();    //used "this->" to access the frontptr inside the LinkedQueue(baseclass)
        while(curr) {
            if (curr->getItem()->getPatientID() == PatientID) {
                if (curr == this -> getFront()) {         //IN case the desired Node is not the first node or the last one
                    this->setFront(curr->getNext());
                }
                else {
                    prev->setNext(curr->getNext());
                }
                if (curr == this->getBack()) {
                    this->setBack(prev);
                }

                delete curr;
                return true;
            }

            //move them to the next node
            prev = curr;
            curr = curr->getNext();

        }
        return false;  // if non of the patients was not found
    }
};
