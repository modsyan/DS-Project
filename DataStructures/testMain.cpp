#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<int> lnk;
    lnk.pushBack(4);
    lnk.push(3);
    lnk.pushBack(42);
    lnk.pushBack(54);
    lnk.push(1);
    lnk.diplay();
    cout << endl;
    lnk.insertAtPositoin(2, 0);
    lnk.diplay();
    // cout << "\n";
    // cout << lnk.atPosition(0);
    // cout << lnk.size();
}