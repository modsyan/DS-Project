#pragma once
#include <iostream>
using namespace std;

class Stack
{
public:
    Stack();
    bool isEmpty();
    void push(char word);
    void pop();
    char peek();
};