#include "Palindrome.h"
#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node()
    {
        data = 'b';
        next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    void push(char l)
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
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    char peek()
    {
        return top->data;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Nothing here " << endl;
        }
        else
        {
            Node *temp = top;
            temp = temp->next;
            delete top;
        }
    }
};