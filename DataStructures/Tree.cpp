#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *rigth = NULL, *left = NULL;
};

template <class T>
class Tree
{
    Node<T> *root;

    Tree<T>()
    {
        root = NULL;
    }

    Tree<T>(T value)
    {
        root->data = value;
    }

    void insert(T data, Node<T>* tree) 
    {
        if (!tree)

    }
    

};