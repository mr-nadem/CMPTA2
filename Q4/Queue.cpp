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

    // Copy all elements
    for (int i = 0 ; i < elementCount; i++) {
        elements[i] = newQ.elements[i];
    }
    
}

// Description: Destructor
Queue::~Queue() {
    // Release elements
    delete elements;
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
    delete elements;
    elements = new int[capacity];
    
    // Copy all the elements
    for (int i = 0 ; i < elementCount; i++) {
        elements[i] = copyQ.elements[i];
    }

}




// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;    
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}
