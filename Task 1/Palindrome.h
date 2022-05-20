#pragma once
#include <iostream>
using namespace std;

class Stack
{
public:
    Stack();
    bool isEmpty();
    void push(char word);
    int pop();
    char peek();
    void pushWord(Stack stack, string s);
};