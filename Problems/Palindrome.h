#include <iostream>

struct Node
{
    char data;
    Node *next = NULL;
};

class Stack
{
public:
    Node *top;

    Stack();
    bool isEmpty();
    void push(char word);
    int pop();
    char peek();
    
};
