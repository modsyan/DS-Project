#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;

    LinkedList<T>()
    {
        head = NULL;
        tail = NULL;
    }
    void pushBack(T value)
    {
        Node<T> *newnode = new Node<T>;
        newnode->data = value;
        
        if (head == NULL)
            head = tail = newnode;
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        if (head != NULL)
        {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void diplay()
    {
        if (head == NULL)
            cout << "Is empty\n";
        else
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    // bool isFound(T value);
    // int size();
    // void insertFirst(T value);
    //     void insertbefore(int item, T value);
    // bool isempty();
    // void diplay();
    // void deleteFirst();
    // void deleteByValue(T value);
    // void deleteByIndex(int index);


// template <class T>
// LinkedList<T>::LinkedList<T>()
// {
//     LinkedList<T>::head = NULL;
//     LinkedList<T>::tail = NULL;
// }

// template <typename T>
// bool LinkedList<T>::isempty()
// {
//     return head;
// }

// template <typename T>
// bool LinkedList<T>::isFound(T value)
// {
//     Node<T> *temp = head;
//     while (!temp)
//     {
//         if (temp->data == value)
//             return 1;
//         temp = temp->next;
//     }
//     return 0;
// }

// template <typename T>
// int LinkedList<T>::size()
// {
//     if (!head)
//         return 0;
//     int cnt = 0;
//     Node<T> *temp = head;
//     while (temp) { temp = temp->next; cnt++;}
//     return cnt;
// }


// template <typename T>
// void LinkedList<T>::insertbefore(int item, T value)
// {
//     if (isempty())
//         insertFirst(value);

//     else
//     {
//         if (isfound(item))
//         {
//             Node<T> *temp = head;
//             Node<T> *newnode = new Node<T>;
//             newnode->data = value;
//             while (temp != NULL && temp->next->data != item)
//             {
//                 temp = temp->next;
//             }
//             newnode->next = temp->next;
//             temp->next = newnode;
//         }
//         else
//             cout << "Sorry, The Item not found -_-";
//     }
// }


// template <typename T>
// void LinkedList<T>::deleteFirst()
// {
//     Node *temp = head;
//     if (isempty())
//         cout << "Sorry, The lst is empty";
//     else
//     {
//         head = temp->next;
//         delete temp;
//         cout << "Num had Deleted\n";
//         diplay();
//     }
// }

// template <typename T>
// void LinkedList<T>::deleteByValue(T value)
// {

//     if (isfound(value))
//     {
//         Node *temp = head->next;
//         Node *tpr = head;
//         if (tpr->data == value)
//         {
//             deleteFirst();
//         }
//         else
//         {
//             while (temp != NULL && temp->data != value)
//             {
//                 temp = temp->next;
//                 tpr = tpr->next;
//             }
//             tpr->next = temp->next;
//             delete temp;
//             cout << "Num had Deleted\n";
//             diplay();
//         }
//     }
//     else
//         cout << "Sorry, The Item is not found!";
// }
// template <typename T>
// void deleteByIndex(T index)
// {
//     if (isempty())
//     {
//         cout << "The lst is empty..";
//     }
//     else
//     {
//         if (index > counter() || index < 1)
//             cout << "sorry the Index out of range! ";
//         else
//         {
//             Node *temp = head->next;
//             Node *tpr = head;
//             if (index == 1)
//             {
//                 deleteFirst();
//             }
//             else
//             {
//                 for (int i = 2; i <= (index - 1); i++)
//                 {
//                     temp = temp->next;
//                     tpr = tpr->next;
//                 }
//                 tpr->next = temp->next;
//                 delete temp;
//                 cout << "The Index had Deleted\n";
//                 diplay();
//             }
//         }
//     }
// }
};
