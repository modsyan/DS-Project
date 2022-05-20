#include <iostream>
using namespace std;
// push_back (done)
// push_front (done)
// pop_front
// pop_back
// getback (done)
// getfront (done)
// erase
// clear
// isempty (done)
// find
// display (done)
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Deque
{
public:
    Node *head;
    Node *tail;
    Deque()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
    void pushFront(int item)
    {
        Node *newitem = new Node;
        newitem->data = item;
        if (isEmpty())
        {
            head = tail = newitem;
        }
        else
        {
            newitem->next = head;
            head = newitem;
        }
    }

    void pushBack(int item)
    {
        Node *newitem = new Node;
        newitem->data = item;
        if (isEmpty())
        {
            head = tail = newitem;
        }
        else
        {
            tail->next = newitem;
            tail = newitem;
        }
    }
    void disPlay()
    {
        if (isEmpty())
            cout << "The list is Empty" << endl;
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    int getFront()
    {
        return head->data;
    }
    int getBack()
    {
        return tail->data;
    }
};

int main()
{
    int item;
    Deque q;
    q.pushFront(4);
    q.pushFront(3);
    q.pushBack(5);
    q.pushBack(6);
    q.disPlay();
}
