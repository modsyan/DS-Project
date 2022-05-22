#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node<T> *parent = NULL;
    Node<T> *left = NULL;
    Node<T> *rigth = NULL;
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

    int insert(T value, Node<T>* node) 
    {
        Node<T> *newLeaf = new Node<T>;
        newLeaf->data = value;

        if(!node) {
            node = newLeaf;
            return 1;
        }

        if(data < node->data)
        {
            node->left = insert(node->left, value);
            node->left->parent = node;
            return 1;
        }

        node->rigth = insert(node->rigth, value);
        node->rigth->parent = node;
    }  

    preOrder(Node<T>* node)
    {
        if(!node)
            return -1;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->rigth);
    }


};

int main()
{
    Tree<int> *tree = new Tree<int>(2);
    
}