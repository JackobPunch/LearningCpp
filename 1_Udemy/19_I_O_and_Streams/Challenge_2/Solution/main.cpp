// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream in_file;
    in_file.open("responses.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::string line{};
    while (std::getline(in_file, line))
    {
        std::cout << line << std::endl;
    }

    in_file.close();
    return 0;
}
