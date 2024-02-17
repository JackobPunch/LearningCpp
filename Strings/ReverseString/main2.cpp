#include <iostream>
#include <string>

using namespace std;

int main()
{
    string bar{"bar"};
    string reversed;
    cout << bar << endl;
    cout << reversed << endl;
    for (int i{}; i < bar.length(); i++)
    {
        reversed[i] = bar[bar.length() - 1 - i];
    }
    cout << reversed << endl;
    return 0;
}