#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class linkedlist
{
public:
    Node *head;

    linkedlist()
    {
        head = NULL;
    }

    bool isempty()
    {
        return (head == NULL);
    }

    bool isfound(int value)
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

    int counter()
    {
        if (isempty())
        {
            cout << "THe lst is empty";
            return 0;
        }
        else
        {
            Node *temp = head;
            int count = 0;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    void insertFirst(int value)
    {
        Node *newnode = new Node;
        newnode->data = value;
        if (isempty())
            newnode->next = NULL;
        else
            newnode->next = head;
        head = newnode;
    }

    void insertbefore(int item, int value)
    {
        if (isempty())
            insertFirst(value);
        else
        {
            if (isfound(item))
            {
                Node *temp = head;
                Node *newnode = new Node;
                newnode->data = value;
                while (temp != NULL && temp->next->data != item)
                {
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
            else
                cout << "Sorry, The Item not found -_-";
        }
    }
    void append(int value)
    {
        if (isempty())
            insertFirst(value);
        else
        {
            Node *newnode = new Node;
            newnode->data = value;
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }

    void diplay()
    {
        if (isempty())
            cout << "The list is empty.. ";
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    void deleteFirst()
    {
        Node *temp = head;
        if (isempty())
            cout << "Sorry, The lst is empty";
        else
        {
            head = temp->next;
            delete temp;
            cout << "Num had Deleted\n";
            diplay();
        }
    }

    void deleteByValue(int value)
    {

        if (isfound(value))
        {
            Node *temp = head->next;
            Node *tpr = head;
            if (tpr->data == value)
            {
                deleteFirst();
            }
            else
            {
                while (temp != NULL && temp->data != value)
                {
                    temp = temp->next;
                    tpr = tpr->next;
                }
                tpr->next = temp->next;
                delete temp;
                cout << "Num had Deleted\n";
                diplay();
            }
        }
        else
            cout << "Sorry, The Item is not found!";
    }
    void deleteByIndex(int index)
    {
        if (isempty())
        {
            cout << "The lst is empty..";
        }
        else
        {
            if (index > counter() || index < 1)
                cout << "sorry the Index out of range! ";
            else
            {
                Node *temp = head->next;
                Node *tpr = head;
                if (index == 1)
                {
                    deleteFirst();
                }
                else
                {
                    for (int i = 2; i <= (index - 1); i++)
                    {
                        temp = temp->next;
                        tpr = tpr->next;
                    }
                    tpr->next = temp->next;
                    delete temp;
                    cout << "The Index had Deleted\n";
                    diplay();
                }
            }
        }
    }
};
