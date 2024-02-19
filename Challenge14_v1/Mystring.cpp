#include <iostream>
#include <cstring>
#include <cctype>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    //       std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    : str(source.str)
{
    source.str = nullptr;
    //        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring()
{
    delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    //    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete[] buff;
    return in;
}

Mystring &Mystring::operator-()
{
    if (str != nullptr)
    {                  // Check if str is not a null pointer
        char *p = str; // Create a char pointer and initialize it with the address of the first character of str
        while (*p)
        {                          // Loop while the character pointed to by p is not the null terminator ('\0')
            *p = std::tolower(*p); // Convert the current character to lowercase
            ++p;                   // Move to the next character in the string
        }
    }
    return *this; // Return the modified object
}

bool Mystring::operator==(const Mystring &rhs) const
{
    // Compare the strings held by the objects
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) != 0);
}

bool Mystring::operator<(const Mystring &rhs) const
{
    return ((std::strcoll(str, rhs.str)) < 0);
}

bool Mystring::operator>(const Mystring &rhs) const
{
    return ((std::strcoll(str, rhs.str)) > 0);
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
    // Calculate the length of the concatenated string
    size_t totalLength = std::strlen(str) + std::strlen(rhs.str);

    // Allocate memory for the concatenated string (+1 for the null terminator)
    char *result = new char[totalLength + 1];

    // Copy the contents of str and rhs.str into the result string
    std::strcpy(result, str);
    std::strcat(result, rhs.str);

    // Create a new Mystring object with the concatenated result
    Mystring resultString(result);

    // Deallocate the dynamically allocated memory
    delete[] result;

    return resultString;
}

Mystring &Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs; // Utilize the existing operator+ overload
    return *this;        // Return a reference to the modified object
}