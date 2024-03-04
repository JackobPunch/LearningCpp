#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__
#include <string>

class InsufficentFundsException : public std::exception
{
public:
    InsufficentFundsException() = default;
    ~InsufficentFundsException() = default;
    virtual const char *what() const noexcept
    {
        return "The withdraw results in a negative balance";
    }
};

#endif // __INSUFFICIENT_FUNDS_EXCEPTION_H__
