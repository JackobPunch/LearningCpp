// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in_file;
    in_file.open("romeoandjuliet.txt");
    if (!in_file)
    {
        cerr << "Problem opening file" << endl;
        return 1;
    }

    int counter_words{}, counter_substrings{};
    string substring{};
    cout << "Enter the substring to search for: ";
    cin >> substring;

    char c{};
    bool first_character = true;
    while (in_file.get(c))
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            if (c == substring[0])
            {
                bool found_substring = true;
                for (int i = 0; i < substring.size(); ++i)
                {
                    if (c != substring[i])
                    {
                        found_substring = false;
                        break; // Break out of the inner loop
                    }
                    in_file.get(c); // Read the next character from the file
                }
                if (found_substring)
                {
                    counter_substrings++;
                }
            }
        }
        else
        {
            if (first_character == false)
                counter_words++;
            first_character = false;
        }
    }
    cout << counter_words << " words were searched..." << endl;
    cout << "The substring " << substring << " was found " << counter_substrings << " times" << endl;

    in_file.close();
    return 0;
}
