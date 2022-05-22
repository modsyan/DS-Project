#include <iostream>
#include "..\DataStructures\"

using namespace std;

int main()
{
    string word;
    cin >> word;
    Stack stack;
    bool isPali = 1;

    for (int i = 0; i < word.size(); i++)
        stack.push(word[i]);

    for (int i = 0; i < word.size(); i++)
    {
        if (stack.peek() != word[i])
        {
            isPali = 0;
            break;
        }
        stack.pop();
    }

    if (isPali)
        cout << "Yes";
    else
        cout << "No";
}