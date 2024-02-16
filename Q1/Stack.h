/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Jaiden Nadem & Mani Samet
 * Date: 2024-02-15
 */
 
class Stack {

    private:
        
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        
        StackNode * head;    

    public:

        // Description: Default Constructor
        Stack();

        // Description: Destructor
        ~Stack();

        // Description: Add a new element to the top of the Stack
        // Time Efficiency: O(n)
        void push(int &num);

        // Description: Returns the top of the stack
        // Precondition: The Stack is not empty
        // Postcondition: The Stack is unchanged
        // Time efficiency: O(n)
        const int peek();

        // Description: Removes top element of this Stack
        // Precondition: The Stack is not empty
        // Time efficiency: O(n)
        void pop();

        // Description: Removes all elements from this Stack
        // Precondition: Stack is not empty
        void popAll();

        // Description: Returns true if Stack is empty
        // Postcondition: Stack is unaltered
        // Time efficiency: O(1)
        const bool isEmpty();

};
