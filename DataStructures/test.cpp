#include <iostream>
using namespace std;

// Class contains variables and pointer
class Node
{
public:
    char c;
    Node *next = NULL;
};

// Class contains all functions
class Stack
{
public:
    Node *top, *temp = NULL, *newWord;

    // Empty Constructor
    Stack()
    {
        top = NULL;
    }

    // Function to check if the stack empty
    bool isEmpty()
    {
        return (top == NULL);
    }

    // Function to filling the stack by inputs
    void push(char letter)
    {
        newWord = new Node();
        newWord->c = letter;
        newWord->next = NULL;

        if (isEmpty())
            top = newWord;
        else
        {
            newWord->next = top;
            top = newWord;
        }
    }

    // Function to take the input to another function and delete the pointer
    char pop()
    {
        temp = top;
        char letter;
        letter = temp->c;
        top = top->next;
        delete temp;
        return letter;
    }

    void Dispaly()
    {
        temp = top;
        while (temp != NULL)
        {

            cout << temp->c;
            temp = temp->next;
        }
    }
};

class Queue
{
public:
    Node *front, *rear, *curr, *temp;

    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void Enqueue(char letter)
    {
        Node *newQeueu = new Node();
        newQeueu->c = letter;

        if (isEmpty())
            front = rear = newQeueu;
        else
        {
            rear->next = newQeueu;
            rear = newQeueu;
        }
    }

    char Dequeue()
    {
        char letter;
        if (isEmpty())
        {
            cout << "Queue is Empty ";
        }
        else if (front == rear)
        {
            letter = front->c;
            delete front;
            front = rear = NULL;
        }
        else
        {
            letter = front->c;
            temp = front;
            front = front->next;
            delete temp;
        }
        return letter;
    }

    void Display()
    {
        curr = front;
        while (curr != NULL)
        {
            cout << curr->c;
            curr = curr->next;
        }
    }
};

int main()
{
    Stack s;
    Queue q;
    string word;
    cin >> word;

    for (int i = 0; i < word.size(); i++){
        q.Enqueue(word[i]);
        s.push(word[i]);
    }
    int size = word.size();
    bool flag = 1;
    while(size--)
    {
        if(q.Dequeue() != s.pop())
        {
            flag = 0;
            break;
        }   
    }
    if (flag)
        cout << "is Pallindrom";
    else
        cout << "Not Pallindrom";
}