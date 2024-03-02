#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__
#include <string>

class IllegalBalanceException
{
public:
    IllegalBalanceException() = default;
    std::string what() const;
    ~IllegalBalanceException() = default;
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
