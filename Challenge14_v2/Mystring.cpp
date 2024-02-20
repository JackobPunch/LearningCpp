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
        // Check for nullptr before accessing strlen
        size_t length = strlen(s);
        str = new char[length + 1];
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

Mystring operator-(Mystring &lhs)
{
    if (lhs.str != nullptr)
    {
        char *p = lhs.str;
        while (*p)
        {
            *p = std::tolower(*p);
            ++p;
        }
    }
    return lhs;
}

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) != 0);
}

bool operator<(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) > 0);
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
    size_t totalSize = std::strlen(lhs.str) + std::strlen(rhs.str);
    char *result = new char[totalSize + 1];
    std::strcpy(result, lhs.str);
    std::strcat(result, rhs.str);
    Mystring newString(result);
    delete[] result;
    return newString;
}

Mystring operator+=(Mystring &lhs, const Mystring &rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator*(const Mystring &lhs, const int &rhs)
{
    size_t originalSize = std::strlen(lhs.str);
    size_t totalSize = originalSize * rhs;
    char *result = new char[totalSize + 1];

    // Copy lhs.str into result 'rhs' times - cause the version from v1 didn't work
    for (int i = 0; i < rhs; ++i)
    {
        std::strcpy(result + (i * originalSize), lhs.str);
    }

    Mystring newString(result);
    delete[] result;
    return newString;
}

Mystring operator*=(Mystring &lhs, const int &rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

Mystring operator++(Mystring &lhs) // pre-increment
{
    if (lhs.str != nullptr)
    {
        char *p = lhs.str;
        while (*p)
        {
            *p = std::toupper(*p);
            ++p;
        }
    }
    return lhs;
}

Mystring operator++(Mystring &lhs, int) // post-increment
{
    Mystring temp(lhs); // make a copy
    operator++(lhs);    // call pre-increment - make sure you call pre-increment!
    return temp;        // return the old value
}