//
// Created by Eyu on 6/7/2021.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

/**
 * Queue class formatting a linked list by using queue and Node class
 * head: the head of the queue, null next pointer in default
 * rear: pointer to the last stored data in current queue, set to the head in default
*/
 template<typename Object>
class Queue {
private:
    Node<Object>* head;
    Node<Object>* rear;

public:
    // Constructor
    Queue() {
        head = nullptr;
        rear = nullptr;
    }

    // Destructor
    ~Queue() {
        while (rear != nullptr) {
            pop();
        }
    }

    // Push an item onto the queue, notice that First In, First Out (the new node will be the bottom of queue)
    void push(Object item) {
        Node<Object>* newNode = new Node<Object>(item);
        //when pushing the first element
        if (head == nullptr) {
            head = newNode;
            rear = newNode;
        }
        else {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    // Pop an item off the queue
    Object pop() {
        if (head == nullptr) {
            return Object();
        }
        Object item = head->getItem();
        // a copy to hold the old front pointer
        Node<Object>* headCopy = head;
        // change the front pointer to the next
        head = head->getNext();
        // delete the old pointer
        delete headCopy;
        // outputs the item
        return item;
    }

    // Determine if an item is in the stack
    bool find(Object item) {
        if (head == nullptr) {
            return false;
        }
        else {
            Node<Object> *currentObject = head;
            while (currentObject != nullptr) {
                if (currentObject->getItem() == item) {
                    return true;
                }
                currentObject = currentObject->getNext();
            }
        }
        return false;
    }

    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void print() {
        std::cout << "Head of queue" << std::endl;
        if (head == nullptr) {
            std::cout << "This is a empty queue" << std::endl;
        }
        else {
            Node<Object> *currentObject = head;
            while (currentObject != nullptr) {
                std::cout << currentObject->getItem() << std::endl;
                currentObject = currentObject->getNext();
            }
            std::cout << "Rear of queue" << std::endl;
            std::cout << std::string(97, '=') << std::endl;
        }
    }

};

#endif //QUEUE_H
