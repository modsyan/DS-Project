#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<int> lnk;
    lnk.pushBack(4);
    lnk.push(3);
    lnk.pushBack(4);
    lnk.pushBack(4);
    lnk.push(1);
    lnk.diplay();
    cout << "\n";
    cout << lnk.atPosition(0);
    cout << lnk.size();
}