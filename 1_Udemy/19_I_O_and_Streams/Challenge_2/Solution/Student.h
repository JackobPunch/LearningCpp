#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>

class Student
{
    friend std::ostream &operator<<(std::ostream &os, const Student &student)
    {
        os << "[Student: " << student.name << ": " << student.points << "]";
        return os;
    }

private:
    std::string name, answers;
    int points;

public:
    Student(std::string name, std::string answers, int points)
        : name{name}, answers{answers}, points{points}
    {
    }
};
#endif