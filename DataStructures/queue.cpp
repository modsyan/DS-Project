#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void disPlay()
    {
        if (isEmpty())
            cout << "The list is Empty" << endl;
        else
        {
            Node *temp = front;
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void enQueue(int value)
    {
        Node *newnode = new Node;
        newnode->data = value;
        if (isEmpty())
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void deQueue()
    {
        if(isEmpty())
            cout << "The list is Empty Now" << endl;
        else if (front == rear)
        {
            delete front;
            front = rear = NULL;
            cout << "The first elemet had deleted.. " << endl;
            disPlay();
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            cout << "The first elemet had deleted.. " << endl;
            disPlay();
        }
    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;
    }
int counter()
    {
        if(isEmpty())
            cout << "The list is empty.." << endl;
        else
        {
            int count = 0;
            Node *temp = front;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    bool isFound(int value)
    {
        Node* temp = front;
        while (temp != NULL)
        {
            if (temp->data == value)
                return true;
            else
                temp = temp->next;
        }
        return false;
    }

    void clear()
    {
        if (isEmpty())
            cout << "The list is aready empty.." << endl;
        else
        {
            while (!isEmpty())
            {
                deQueue();
            }
        }
    }
};

int main()
{
    int item;
    Queue q;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Item to enQueue: ";
        cin >>
            item;
        q.enQueue(item);
    }
    q.disPlay();

    q.clear();
    q.clear();
}