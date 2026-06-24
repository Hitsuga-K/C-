#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == 3)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
        cout << "*";
    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        if (i == 1 || i == 2 || i == 5 || i == 6)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        if (i == 1 || i == 6)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;

    return 0;
}