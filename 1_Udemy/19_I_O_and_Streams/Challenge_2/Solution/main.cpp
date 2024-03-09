// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in_file;
    in_file.open("responses.txt");
    if (!in_file)
    {
        cerr << "Problem opening file" << endl;
        return 1;
    }

    vector<string> names, answers;
    vector<int> points_vec;
    string line{}, right_answers{};
    int counter{};
    double average{};

    while (getline(in_file, line))
    {
        if (counter != 0)
        {
            if ((counter % 2) != 0)
            {
                names.push_back(line);
            }
            else
            {
                answers.push_back(line);
            }
        }
        else
        {
            right_answers = line;
        }
        counter++;
    }

    in_file.close();

    right_answers.erase(std::remove_if(right_answers.begin(), right_answers.end(), ::isspace), right_answers.end());
    for (auto &name : names)
    {
        name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    }
    for (auto &answer : answers)
    {
        answer.erase(std::remove_if(answer.begin(), answer.end(), ::isspace), answer.end());
    }
    for (const auto &answer : answers)
    {
        int points{};
        for (int i = 0; i < answer.size(); ++i)
        {
            if (answer[i] == right_answers[i])
                points++;
        }
        points_vec.push_back(points);
    }

    cout << std::setw(14) << left << "Student" << setw(14) << right << "Score" << endl;
    cout << "----------------------------" << endl;

    for (int i{}; i < names.size(); ++i)
    {
        cout << std::setw(14) << left << names[i] << setw(14) << right << points_vec[i] << endl;
    }
    cout << "----------------------------" << endl;
    for (const auto &points : points_vec)
    {
        average += points;
    }
    average = average / points_vec.size();
    cout << std::setw(14) << left << "Average score" << setw(14) << right << average << endl;

    return 0;
}
