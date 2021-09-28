//
// Created by Eyu on 9/27/2021.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

template<typename Object>
class Stack {
private:
    Node<Object>* top;

public:

    // Constructor
    Stack() {
        top = nullptr;  // By default the stack will be empty
    }

    // Destructor
    // Automatically call when main function ends
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    // Push an item onto the stack, notice that First In, Last Out (the new node will be the top of stack)
    void push(Object item) {
        Node<Object>* newNode = new Node<Object>(item, top);
        top = newNode;
        std::cout << "--> push one new item onto stack" << std::endl;
    }

    // Pop an item off the stack
    Object pop() {
        if (top == nullptr) {
            // The stack is empty so return a default object
            return Object();
        }
        //else if...
        Object item = top->getItem();
        // a copy to hold the old top pointer
        Node<Object>* topCopy = top;
        // change the top pointer to the next
        top = top->getNext();
        // delete the old pointer
        delete topCopy;
        std::cout << "--> pop one item from stack" << std::endl;
        // outputs the item
        return item;
    }

    // Determine if an item is in the stack
    bool find(Object item) {
        Node<Object>* currentObject = top;
        // read through the whole stack
        while (currentObject != nullptr) {
            if (currentObject->getItem() == item) {
                return true;
            }
            currentObject = currentObject->getNext();
        }
        return false;
    }

    // Is the stack empty?
    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }

    // Print the stack
    void print() {
        std::cout << std::string(80, '=') << std::endl;
        std::cout << "Top of stack" << std::endl;
        Node<Object>* currentObject = top;
        while (currentObject != nullptr) {
            std::cout << currentObject->getItem() << std::endl;
            currentObject = currentObject->getNext();
        }
        std::cout << "Bottom of stack" << std::endl;
        std::cout << std::string(80, '=') << std::endl;
    }

};

#endif //STACK_H
