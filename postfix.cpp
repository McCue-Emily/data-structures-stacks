#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

#include "linkedstack.h"
#include "node.h"

string evaluateInfixExpression(string);
float evaluatePostfixExpression(string);
float operandAssignment(LinkedStack<float>*);

using namespace std;

int main() {

    bool exit = false;
    string infixExpression;
    string postfixExpression;
    float result;

    while (exit == false) {

        cout << "Infix: ";
        getline(cin, infixExpression);

        postfixExpression = evaluateInfixExpression(infixExpression);
        if (postfixExpression == "invalid") {
            return 0;
        }
        cout << "Postfix: " << postfixExpression << endl;

        result = evaluatePostfixExpression(postfixExpression);
        
        if (result - floorf(result) == 0) {
            cout << "Result: " << result << endl;
        } else {
            cout << fixed <<  setprecision(1) << "Result: " << result << endl;
        }
            
        exit = true;
    }
return 0;
}

string evaluateInfixExpression(string infixExpression) {
    LinkedStack<char>* operatorStack = new LinkedStack<char>();

    string postfixExpression;

    for (int i = 0; i < infixExpression.length(); i++) {
        if (isspace(infixExpression.at(i))) {
            continue;

        } else if (isdigit(infixExpression.at(i))) {

            postfixExpression += infixExpression.at(i);
            if (postfixExpression.length() >= 2) {
                postfixExpression += operatorStack->peek();
                operatorStack->pop();
            }

        } else {
            char character = infixExpression.at(i);
            switch(character) {
                case '+':
                    operatorStack->push(character);
                    break;
                case '-':
                    operatorStack->push(character);
                    break;
                case '*':
                    operatorStack->push(character);
                    break;
                case '/':
                    operatorStack->push(character);
                    break;
                default:
                    cout << "Invalid character" << endl;
                    string invalid = "invalid";
                    return invalid;
            }
        }
    }
    return postfixExpression;
}

float evaluatePostfixExpression(string postfixExpression) {
    float operand1;
    float operand2;
    float result;

    LinkedStack<float>* resultStack = new LinkedStack<float>();

    for (int i = 0; i < postfixExpression.length(); i++) {

    if (isdigit(postfixExpression.at(i))) {
        float charToFloat = postfixExpression.at(i) - 48;
        resultStack->push(charToFloat);
    } else {
        char character = postfixExpression.at(i);
        switch(character) {
            case '+':
                operand2 = operandAssignment(resultStack);
                operand1 = operandAssignment(resultStack);
                result = operand2 + operand1;
                resultStack->push(result);
                break;
            case '-':
                operand2 = operandAssignment(resultStack);
                operand1 = operandAssignment(resultStack);
                result = operand1 - operand2;
                resultStack->push(result);
                break;
            case '*':
                operand2 = operandAssignment(resultStack);
                operand1 = operandAssignment(resultStack);
                result = operand1 * operand2;
                resultStack->push(result);
                break;
            case '/':
                operand2 = operandAssignment(resultStack);
                operand1 = operandAssignment(resultStack);
                result = operand1 / operand2;
                resultStack->push(result);
                break;
            }
        }
    }
    result = resultStack->peek();
    resultStack->pop();

    return result;
}

float operandAssignment(LinkedStack<float>* result) {
    float operand;
    operand = result->peek();
    result->pop();

    return operand;
}
