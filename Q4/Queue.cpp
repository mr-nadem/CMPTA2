/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Jaiden Nadem & Mani Samet
 * Date: 2024-02-15
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
// Postcondition: Resizes array capacity to double if full
// Time Efficiency: O(1) or O(n) if resized
void Queue::enqueue(int newElement) {
    // Space allocation
    if (elementCount == capacity) {
        capacity *= 2;

        int *updatedElements = new int[capacity];

        for (unsigned int i = frontindex, j = 0; j < elementCount;i = (i + 1) % (capacity / 2), j++) {
            updatedElements[j] = elements[i];
        }

        // Delete old array and update elements
        delete[] elements;
        elements = updatedElements;

        // Fix the indices
        frontindex = 0;
        backindex = elementCount; 
    }

    // Enqueuing
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;
}


// Description: Removes the frontmost element
// Precondition: Queue not empty
// Postcondition: Resizes array to half size if # of elements is less than a quarter of the capacity
// Time Efficiency: O(1) or O(n) if resized
void Queue::dequeue() {

    if (!isEmpty()) { // Precondition

        // Dequeuing process
        elementCount--;
        frontindex = (frontindex + 1) % capacity;

        // Space allocation
        if ((elementCount < capacity / 4) && (capacity != INITIAL_CAPACITY)) {

            int previousCapacity = capacity;

            if ((capacity / 2) < INITIAL_CAPACITY) { // Checks if the capacity needs to be set to iniial
                capacity = INITIAL_CAPACITY;
            } else { // If not just half capacity
                capacity = capacity / 2;
            }

            int *updatedElements = new int[capacity]; // Creates array with new capacity

            // Uses previous capacity in order to grab all the elements in proper order.
            for (unsigned int i = frontindex, j = 0; j < elementCount; i = (i + 1) % (previousCapacity), j++) {
                updatedElements[j] = elements[i];
            }

            // Delete old array and update elements to be the updated array. 
            delete[] elements;
            elements = updatedElements;

            // Fix the indices
            frontindex = 0;
            backindex = elementCount; 
        }
        
    } else {
        cout << "FAILED: Queue Empty";
    }
    
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    if (!isEmpty()) {
        return elements[frontindex];  
    } else {
        cout << "\nFAILED: Queue Empty\n";
        return -1;
    }
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}

// Description: Prints all elements ignoring the gaps or unused indices
void Queue::printQueue() {
    for (int i = frontindex, j = 0; j < elementCount; j++, i = (i+1) % capacity) {
        cout << elements[i] << " ";
    }
    cout << "\nElement Count: " << elementCount << "\n";
    cout << "Capacity: " << capacity << "\n";
    cout << endl;
}

