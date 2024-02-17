#include <iostream>
#include <string>

using namespace std;

int main()
{
    string letters;
    cout << "If you write some letters I will give you pyramid of it" << endl;
    getline(cin, letters);
    cout << "Your letters " << letters << endl;
    cout << "The number of your letters is " << letters.length() << endl;
    int j{}, y{letters.length()};
    while (y > 0)
    {
        cout << " ";
        y--;
    }
    cout << letters[0] << endl;
    for (int i{}; i < letters.length() - 1; i++)
    {
        y = letters.length() - i - 1;
        while (y > 0)
        {
            cout << " ";
            y--;
        }
        j = 0;
        while (j <= i)
        {
            cout << letters[j];
            j++;
        }
        while (j >= 0)
        {
            cout << letters[j];
            j--;
        }
        cout << endl;
    }
    return 0;
}