**# data-structures-stacks

## Project Goals
The goal of this project is to:
1.	Familiarize students with **stacks**
2.  Familiarize students with **using Data Structures**.

## Program
We commonly write arithmetic expressions in the so-called infix form. That is, with each operator placed between its operand, as below:  
<p align="center">
(5+6)*(4/3)  </p>

Although we are comfortable writing expressions in this form, infix form has the disadvantage that parentheses must be used to indicate the order in which operators
are to be evaluated. These parentheses, in turn, complicate the evaluation process. Evaluation is much easier if we can simply evaluate operators from left to right.
Unfortunately, this evaluation will not work with the infix form of arithmetic expressions. However, it will work if the expression is in postfix form. In the postfix form of an arithmetic expression, each operator is placed immediately after its operands. The expression above is written in postfix form as
<p align="center">
56+43/*  </p>

Note that both forms place the numbers in the same order (reading from left to right). The order of the operators is different, however, because the operators in the postfix form are positioned in the order that they are evaluated. The resulting postfix expression is hard to read at first, but it is easy to evaluate programmatically. We will do so with stacks. Suppose you have an arithmetic expression in postfix form that consists of a sequence of single digit, nonnegative integers and the four basic arithmetic operators (+,-,\*,/). This expression can be evaluated using the following algorithm in conjuction with a stack of floating-point numbers.

Read the expression character-by-character. As each character is read in:
*	If the character corresponds to a single digit number (characters ‘0’ to ‘9’), then push the corresponding floating-point number onto the stack.
*	If the character corresponds to one of the arithmetic operators (characters ‘+’, ‘-‘, ‘\*’, ‘/’), then 
    * Pop a number off of the stack. Call it operand1.
    * Pop a number off of the stack. Call it operand 2.
    * Combine these operands using the arithmetic operator, as follows
      * Result = operand2 operator operand1
  * Push result onto the stack.

When the end of the expression is reached, pop the remaining number off the stack. This number is the value of the expression. Applying this algorithm to the arithmetic expression  
<p align="center">
34+52/*  </p>

Results 17.5 as expected.  

## Requirements
Create a program that reads the infix form of an arithmetic expression, evaluates it, outputs the postfix expression, and outputs the result. Assume that the expression consists of single-digit, nonnegative integers (‘0’ to ‘9’) and the four basic arithmetic operators (‘+’,’-‘,’\*’,’/’). Further assume that the arithmetic expression is input from the keyboard with all the characters separated by white space on one line. Save your program in a file called postfix.cpp.  

Use a linked based implementation for your Stack data structure. **
