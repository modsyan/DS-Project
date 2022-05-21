#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next = NULL;
    Node<T> *prev = NULL;
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
        
        if (!head)
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

    int insertAtPositoin(T val, int index) 
    {
        if(index < 0 || index > size())
            return 0;
        Node<T> *itt = head;
        Node<T> *newNode = new Node<T>;
        newNode->data = val;
        // index -= 1;
        while(index--)
            itt = itt->next;
        newNode->next = itt->next;
        itt->next = newNode;
        newNode->prev = itt;
        newNode->next->prev = newNode;
    }

    void diplay()
    {
        if (!head)
            cout << "Is empty\n";
        else
        {
            Node<T> *cur = head;
            while(cur != NULL)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
        }
    }

    bool isFound(T value)
    {
        Node<T> *cur = head;
        while (cur)
        {
            if (cur->data == value)
                return 1;
            cur = cur->next;
        }
        return 0;
    }

    T atPosition(int index) 
    {
        if(!head)
            return -1;
        Node<T> *cur = head;
        while(index--)
            cur = cur->next;
        return cur->data;
    }

    bool isempty()
    {
        return head;
    }

    int size()
    {
        if (!head)
            return 0;
            
        Node<T> *temp = head;
        int cnt = 0;
        while (temp)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    //void insertbefore(int item, T value);
    // void deleteFirst();
    // void deleteByValue(T value);
    // void deleteByIndex(int index);





    // void insertbefore(int item, T value)
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
