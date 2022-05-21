#include <iostream>
#include "Palindrome.h"
using namespace std;

Stack::Stack()
{
    top = NULL;
}

bool Stack::isEmpty()
{
    return top == NULL;
}

void Stack::push(char l)
{
    Node *newWord = new Node;
    newWord->data = l;

    if (isEmpty())
    {
        top = newWord;
    }
    else
    {
        newWord->next = top;
        top = newWord;
    }
}

int Stack::pop()
{
    if (isEmpty())
        return -1;
    else
    {
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }
}

char Stack::peek()
{
    return top->data;
}
