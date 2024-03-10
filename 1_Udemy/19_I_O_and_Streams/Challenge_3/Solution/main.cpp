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
    bool previously_letter = false;
    while (in_file.get(c))
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            previously_letter = true;
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
            if (previously_letter == true)
                counter_words++;
            previously_letter = false;
        }
    }
    cout << counter_words << " words were searched..." << endl;
    cout << "The substring " << substring << " was found " << counter_substrings << " times" << endl;

    in_file.close();
    return 0;
}
