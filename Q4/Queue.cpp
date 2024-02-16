/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author:
 * Date:
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() {
    elements = new int[INITIAL_CAPACITY];
}

// Description: Copy constructor
// Time Efficiency: O(n)
Queue::Queue(const Queue &newQ) {

    // Copy all the non-dynamic variables
    capacity = newQ.capacity;
    elementCount = newQ.elementCount;
    frontindex = newQ.frontindex;
    backindex = newQ.backindex;

    // Set element size to the Queues capacity
    elements = new int[capacity];

    cout << "Starting copy: ";
    // Copy all elements
    for (int i = frontindex, j = 0; j < elementCount; i = (i + 1) % capacity, j++) {
        elements[i] = newQ.elements[i];
    }
    
}

// Description: Destructor
Queue::~Queue() {
    // Release elements
    delete[] elements;
}

// Description: Overloaded operator assignment
// Time Efficiency: O(n)
void Queue::operator=(Queue &copyQ) {

    // Copy all non-dynamic variables
    capacity = copyQ.capacity;
    elementCount = copyQ.elementCount;
    frontindex = copyQ.frontindex;
    backindex = copyQ.backindex;

    // Create new array with the capacity of copyQ
    delete[] elements;
    elements = new int[capacity];
    
    // Copy all the elements
    for (int i = frontindex, j = 0; j < elementCount; i = (i + 1) % (capacity), j++) {
        elements[i] = copyQ.elements[i];
    }

}




// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
    // Space allocation
    if (elementCount == capacity) {
        capacity *= 2;

        int *updatedElements = new int[capacity];

        for (unsigned int i = frontindex, j = 0; j < elementCount;i = (i + 1) % (capacity / 2), j++) {
            updatedElements[j] = elements[i];
        }

        delete[] elements;
        elements = updatedElements;
        frontindex = 0;
        backindex = elementCount;  // Update backindex after copying elements
    }

    // Enqueuing
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;
}


// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {

    if (!this->isEmpty()) {
        // Space allocation
        if (elementCount < capacity / 4) {
            capacity = capacity / 2;
            if (capacity < INITIAL_CAPACITY) {
                capacity = INITIAL_CAPACITY;
            }

            int *updatedElements = new int[capacity];

            for (unsigned int i = frontindex, j = 0; j < elementCount; i = (i + 1) % (capacity * 2), j++) {
                updatedElements[j] = elements[i];
            }

            delete[] elements;
            elements = updatedElements;
            frontindex = 0;
            backindex = elementCount;  // Update backindex after copying elements
        }

        elementCount--;
        frontindex = (frontindex + 1) % capacity;
        return;
    } else {
        cout << "FAILED: Queue Empty";
    }
    
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    if (!this->isEmpty()) {
        return elements[frontindex];  
    } else {
        cout << "FAILED: Queue Empty";
        return -1;
    }
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}

void Queue::printQueue() {
    for (int i = 0; i < elementCount; i++) {
        cout << elements[i] << " ";
    }
    cout << "\nElement Count: " << elementCount << "\n";
    cout << "Capacity: " << capacity << "\n";

    cout << endl;
}

