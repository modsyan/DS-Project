#include <iostream>
using namespace std;

struct PhoneRecord
{
    string name;
    string phoneNumber;
    PhoneRecord *next;
};

class Contacts
{
public:
    PhoneRecord *head;
    PhoneRecord *tail;
    void insert(string name, string phoneNumber);
    void print();

    Contacts();
};

void Contacts::insert(string name, string phoneNumber)
{
    PhoneRecord *tmp = new PhoneRecord;

    tmp->name = name;
    tmp->phoneNumber = phoneNumber;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}

void Contacts::print()
{
    PhoneRecord *current = head;

    while (current != NULL)
    {
        cout << "Name: " << current->name << " PhoneNumber: " << current->phoneNumber << "\n";
        current = current->next;
    }
}

Contacts::Contacts()
{
    head = NULL;
    tail = NULL;
}

struct contact {
    string name;
    string phone;
};


int main()
{
    Contacts list;

    char ask = '2';
    string tmpName, tmpNumber;
    while (ask != '\n')
    {

        cout << "1- add contact\n2-remove contact\n3-search contacts\n4-clearAll\nPress Enter To Exit";
        cin >> ask;
        if(ask == '1')
        {
            cout << "Name: ";
            cin >> tmpName;
            cout << endl << "Phone: ";
            cin >> tmpNumber;
            list.insert(tmpName, tmpNumber);
        }
        else if(ask == '2')
        {
            cout << "Name?";
            cin >> tmpName;
            if (list.remove(tmpName) == 0)
                cout << "name not found";
            else
                cout << "name is removed";
        }
        else if(aks == '3')
        {
            cout << "Name: ";
            // contact tmp = (if (list.search(tmpName) == -1) return unknown, unknown;
            // else 
            // return );
        }

    }



    SaifMobiles.print();
}