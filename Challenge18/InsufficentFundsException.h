#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__
#include <string>

class InsufficentFundsException
{
public:
    InsufficentFundsException() = default;
    std::string what() const;
    ~InsufficentFundsException() = default;
};

#endif // __INSUFFICIENT_FUNDS_EXCEPTION_H__
