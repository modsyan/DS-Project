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
        }
    }

    char peek()
    {
        return top->data;
    }
};

int main()
{
    string word;
    // cin >> word;
    word = "LOOL";
    Stack stack;
    bool isPali = 1;

    for (int i = 0; i < word.size(); i++)
        stack.push(word[i]);

    for (int i = 0; i < word.size(); i++)
    {
        if (stack.peek() != word[i])
        {
            isPali = 0;
            break;
        }
        stack.pop();
    }

    if (isPali)
        cout << "Yes";
    else
        cout << "No";
}