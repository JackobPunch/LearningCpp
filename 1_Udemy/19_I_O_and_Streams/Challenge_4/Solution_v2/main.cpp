// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream in_file{"romeoandjuliet"};
    std::ofstream out_file{"romeoandjuliet_out.txt"};
    if (!in_file)
    {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
    if (!out_file)
    {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }
    int number_of_line{1};
    std::string line{};
    bool blank_line = true;
    while (std::getline(in_file, line))
    {
        blank_line = true;
        for (int i{}; i < line.size(); ++i)
        {
            if (line[i] != ' ')
            {
                blank_line = false;
                std::string str_number_of_line = std::to_string(number_of_line);
                std::string new_line = str_number_of_line + " " + line;
                out_file << new_line << std::endl;
                number_of_line++;
                break;
            }
        }
        if (blank_line == true)
            out_file << line << std::endl;
    }
    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();

    return 0;
}
