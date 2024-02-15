
#include <iostream>
#include "Stack.h"

Stack::Stack() {
    elementCount = 0;
    head = nullptr;
}


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
    elementCount++;
}

const int Stack::peek() {
    StackNode * current;
    current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    return current->data;
}

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

        elementCount--;
    } 
    

}

const bool Stack::isEmpty() {
    if (elementCount == 0) {
        return true;
    } else {
        return false;
    }
}
