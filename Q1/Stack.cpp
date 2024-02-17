/* 
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Jaiden Nadem & Mani Samet
 * Date: 2024-02-15
 */

#include <iostream>
#include "Stack.h"

// Description: Default constructor
Stack::Stack() {
    head = nullptr;
}

// Description: Destructor
Stack::~Stack() {
    delete head;
}

// Description: Add a new element to the top of the Stack
// Time Efficiency: O(n)
void Stack::push(int &num) {

    if (head == nullptr) {
        head = new StackNode();
        head->data = num;
        head->next = nullptr;
    } else {
        StackNode * newNode = new StackNode();
        newNode->data = num;
        newNode->next = nullptr;

        StackNode * current = head;
        while(current->next != nullptr) {
            current = current-> next;
        }
        current->next = newNode;
    } 
}

// Description: Returns the top of the stack
// Precondition: The Stack is not empty
// Postcondition: The Stack is unchanged
// Time efficiency: O(n)
const int Stack::peek() {
    StackNode * current;
    current = head;

    if (isEmpty() == true) {
        return -1;
    }

    while (current->next != nullptr) {
        current = current->next;
    }

    return current->data;
}

// Description: Removes top element of this Stack
// Precondition: The Stack is not empty
// Time efficiency: O(n)
void Stack::pop() {

    if (isEmpty() == false) {

        if (head->next == nullptr) {
            delete head;
            head = nullptr;

        } else {

            StackNode * current;
            StackNode * prev;

            prev = head;
            current = head->next;

            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            delete current;
            prev->next = nullptr;
            
        }

    } 
    

}

// Description: Removes all elements from this Stack
// Precondition: Stack is not empty
void Stack::popAll() {
    if (isEmpty() == false) {
        delete head;
        head = nullptr;
    }
}

// Description: Returns true if Stack is empty
// Postcondition: Stack is unaltered
// Time efficiency: O(1)
const bool Stack::isEmpty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}