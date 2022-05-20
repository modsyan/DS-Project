#include "Palindrome.h"
#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next = NULL;
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
        return top == NULL;
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

    int pop()
    {
        if (isEmpty())
            return -1;
        else
        {
            Node *tmp = top;
            top = top->next;
            delete tmp;
            return top->data;
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

    void pushWord(Stack stack, string s)
    {
        for (int i = 0; i < s.size(); i++)
            stack.push(s[i]);
    }

    char peek()
    {
        return top->data;
    }
};