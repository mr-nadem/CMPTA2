/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Jaiden Nadem & Mani Samet
 * Date: 2024-02-16
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;


// Description: Determines priority of the operations.
// Precondition: non-empty / Valid Input Token
// Postcondition: Returns integer of operation priority (0 for lowest, 2 for highest).
// Time efficiency: O(1) - Constant time complexity.
int OperationPriority(Token operation) {

    if (operation.tt == asttok || operation.tt == slashtok){ // if * or / higher pressedance
        return 2;
        }

    else if (operation.tt == pltok || operation.tt == mitok){ // + or - lower pressedance
        return 1;
    }
    
    return 0;
}


// Description: Performs one of the arithmetic operations on num1 and num2 .
// Precondition: There must be a non-empty / Valid Input Token
// Postcondition: Returns result of operation on num1 and num2.
// Time efficiency: O(1)
int getOperationVal(Token operation, int num1, int num2){

    if (operation.tt == pltok) // + addition
        return num1 + num2;

    if (operation.tt == mitok) // - subtraction
        return num1 - num2;

    if (operation.tt == asttok) // * multiplication
        return num1 * num2;

    if (operation.tt == slashtok) // / division
        return num1 / num2;

    return 0;
}



int main() {

    Scanner S(cin); // object of class Scanner with parameter cin
    Token t;
    Stack<Token> number_stack, operator_stack; // stacks to hold numbers and operators
    t = S.getnext();

    // Evaluate  incoming tokens until end of expression
    while (t.tt != eof) {

        if (t.tt == integer){
            number_stack.push(t);
        }

        else if (t.tt == lptok){
            operator_stack.push(t);

        }
        else if (t.tt == rptok) {
            while (!operator_stack.isEmpty() && operator_stack.peek().tt != lptok) {
                Token operation = operator_stack.pop();
                Token num2 = number_stack.pop();
                Token num1 = number_stack.pop();

                int result = getOperationVal(operation, num1.val, num2.val);
                Token resultToken;
                resultToken.tt = integer;
                resultToken.val = result;
                number_stack.push(resultToken);
            }
            operator_stack.pop(); // pops the left parenthesis from operator_tack
        }

        else if (t.tt == pltok || t.tt == mitok || t.tt == asttok || t.tt == slashtok) {
            while (!operator_stack.isEmpty() && OperationPriority(operator_stack.peek()) >= OperationPriority(t)) {
                Token operation = operator_stack.pop();
                Token num2 = number_stack.pop();
                Token num1 = number_stack.pop();
                int result = getOperationVal(operation, num1.val, num2.val);
                Token resulttok;
                resulttok.tt = integer;
                resulttok.val = result;
                number_stack.push(resulttok);
            }
            operator_stack.push(t); // push current operator in operator_stack
        }   

    t = S.getnext(); //get next token
    }

    // Evaluate remaining operators
    while (!operator_stack.isEmpty()){

        Token operation = operator_stack.pop();
        Token num2 = number_stack.pop();
        Token num1 = number_stack.pop();
        int result = getOperationVal(operation, num1.val, num2.val);
        Token resulttok;
        resulttok.tt = integer;
        resulttok.val = result;
        number_stack.push(resulttok);
    }

    // print the result
    if (!number_stack.isEmpty()){
        cout << number_stack.peek().val << endl;
    }
    return 0;
}
