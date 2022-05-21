#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
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
            newitem->next = newitem->prev = NULL;
        }
        else
        {
            head->prev = newitem;
            newitem->next = head;
            head = newitem;
            head->prev = NULL;
        }
    }
    void pushBack(int item)
    {
        Node *newitem = new Node;
        newitem->data = item;
        if (isEmpty())
        {
            head = tail = newitem;
            newitem->next = newitem->prev = NULL;
        }
        else
        {
            tail->next = newitem;
            newitem->prev = tail;
            tail = newitem;
            tail->prev = NULL;
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
            head->prev = NULL;
            delete temp;
        }
    }
    void popBack()
    {

        if (isEmpty())
        {

            cout << "Nothing here ";
        }

        else if (head == tail)
        {
            delete tail;
            tail = head = NULL;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void erase(int item)
    {
        Node *temp;
        if (isEmpty())
        {
            cout << "empty list";
        }
        else if (head->data == item)
        {
            popFront();
        }
        else
        {
            temp = head->next;
            while (temp != NULL)
            {
                if (temp->data == item)
                    break;
                temp = temp->next;
            }
        }

        if (temp == NULL)
        {
            cout << "item not found" << endl;
        }
        else if (temp->next == NULL)
        {
            popBack();
        }
        else
        {

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
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
    void display()
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
    // bool isFound(int value)
    // {
    //     Node *temp = front;
    //     while (temp != NULL)
    //     {
    //         if (temp->data == value)
    //             return true;
    //         else
    //             temp = temp->next;
    //     }
    //     return false;
    // }
};

int main()
{
    int item;
    Deque q;
    q.pushFront(4);
    q.pushFront(3);
    q.pushFront(2);
    q.display();
    q.pushBack(5);
    q.pushBack(6);
    q.pushBack(7);
    q.display();
    q.popBack();
    q.display();
    q.erase(5);
    q.display();

    return 0;
}