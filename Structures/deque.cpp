#include <iostream>
using namespace std;
// push_back
// push_front
// pop_front
// pop_back
// getback
// getfront
// erase
// clear
// isempty (done)
// find
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
};
