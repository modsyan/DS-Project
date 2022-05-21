#include <iostream>
using namespace std;
// push_back (done)
// push_front (done)
// pop_front (done)
// pop_back
// getback (done)
// getfront (done)
// erase (done)
// clear (done)
// isempty (done)
// search (done)
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
    void popFront()
    {
        if (isEmpty())
        {
            cout << "Nothing here" << endl;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void popBack()
    {
        if (isEmpty())
        {
            cout << "Nothing here" << endl;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
        }
    }

    void clear()
    {
        if (isEmpty())
            cout << "The list is aready empty.." << endl;

        else
        {
            while (!isEmpty())
            {
                popFront();
            }
        }
    }
    bool search(int value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == value)
                return true;
            else
                temp = temp->next;
        }
        return false;
    }
    void erase(int item)
    {
        Node *delptr = head;
        if (isEmpty())
        {
            cout << "List is empty , no items to delete \n";
        }
        else if (head->data == item)
        {
            head = head->next;
            delete delptr;
        }
        else
        {
            Node *prev = NULL;
            delptr = head;
            while (delptr->data != item)
            {
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = delptr->next;
            delete delptr;
        }
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
    q.erase(4);
    q.disPlay();
    q.popBack();
    q.disPlay();
}
