//
// Created by Rashwan's on 24/11/2024.
//
#pragma once
#include "priQueue.h"
#include "LinkedQueue.h"

/*template <typename T>
struct CanceledItem {
    T item;       // The canceled item
    int priority; // The priority of the canceled item

    CanceledItem(const T& item, int priority) : item(item), priority(priority) {}
};*/

template <typename T>
class ExtendedCancellablePriorityQueue : public priQueue<T> {
private:
    LinkedQueue<T> canceledQueue; // Queue to temporarily store canceled cars

public:
    ExtendedCancellablePriorityQueue() : priQueue<T>(), canceledQueue() {}

    // Cancel a request and move the car to the canceledQueue
    bool cancelRequestAndHold(int identifier, T& canceledItem) {
        priNode<T>* prev = nullptr;
        priNode<T>* curr = this->getHead(); //88888888// Use "this->" to access the frontPtr from the base class

        while (curr) {
            // Assuming T has a method `getID()` to return the identifier
            if (curr->getItem()->getID() == identifier) {
                int priority = curr->getPri();
                // Relink the nodes
                if (prev) {
                    prev->setNext(curr->getNext());
                } else {
                    this->setHead(curr->getNext());
                }

                canceledItem = curr->getItem(priority); // Extract the item
                //// Store it in the canceledQueue.
                canceledQueue.enqueue(canceledItem);
                delete curr; // Free memory
                return true;
            }

            prev = curr;
            curr = curr->getNext();
        }

        return false; // If the car was not found
    }

    // Reinstate a canceled car back into the main priority queue
    bool reinstateCanceledCar() {
        if (canceledQueue.isEmpty()) {
            return false; // No canceled cars to reinstate
        }

        T canceledItem;
        canceledQueue.dequeue(canceledItem);
        int priority = 0;
        this->enqueue(canceledItem,priority); // Add back to the main queue
        return true;
    }

    bool isCanceledQueueEmpty() const {
        return canceledQueue.isEmpty();
    }

};