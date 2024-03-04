#include <iostream>
#include <string>

using namespace std;

string reverse_string(const string &str)
{
    string reversed2{};
    reversed2.resize(str.length());
    // Write your code below this line
    for (int i{}; i < str.length(); i++)
    {
        reversed2[i] = str[str.length() - 1 - i];
    }

    // Write your code abocve this line
    return reversed2;
}

int main()
{
    string bar{"bar"};
    string reversed{};
    cout << reversed << endl;
    reversed.resize(bar.length());
    for (int i{}; i < bar.length(); i++)
    {
        reversed[i] = bar[bar.length() - 1 - i];
    }
    cout << reversed << endl;
    cout << reverse_string(reversed) << endl;
    return 0;
}