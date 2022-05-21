#include <iostream>
using namespace std;

template <class K, class V>
struct pairs
{
    K key;
    V value;
    pairs<K, V> *Next = NULL;
    pairs<K, V> *Prev = NULL;
};

template <class K, class V>
class Map
{
public:
    pairs<K, V> *head, *tail;

    Map<K, V>()
    {
        head = tail = NULL;
    }

    void insert(K key, V value)
    {
        pairs<K, V> *newPairs = new pairs<K, V>;
        newPairs->key = key;
        newPairs->value = value;

        if (!head)
            head = tail = newPairs;
        else
        {
            tail->Next = newPairs;
            newPairs->Prev = tail;
            tail = newPairs;
        }
    }

    int remove(K key)
    {
        if (!head)
            return 0;
        pairs<K, V> *it = head;

        if(it->key = key)
        {
            pairs<K, V> tmp = it;
            it = it->Next;
            it->Prev = NULL;
            delete tmp;
            return 1;
        }
        while (it->Next->key != key && it)
            it = it->Next;
        if(!it)
            return 0;

        pairs<K, V> *tmp = it->Next;
        it->Next->Next->Prev = it;
        it->Next = it->Next->Next;
        delete tmp;
        return 1;
    }

    int search(K key)
    {
    }

    void display()
    {
        pairs<K, V> *cur = head;
        while(head)
        {
            cout << "Key: " <<cur->key << " Value: " <<cur->value << endl;
            cur = cur->Next;
        }
    }
};


int main()
{
    Map<int, int> map;
    map.insert(1001, 1);
    map.insert(1002, 11);
    map.insert(1003, 111);
    map.remove(1003);
    map.insert(1004, 1111);
    map.display();
}