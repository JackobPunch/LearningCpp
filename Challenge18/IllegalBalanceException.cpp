#include "IllegalBalanceException.h"

std::string IllegalBalanceException::what() const
{
    return "Couldn't create account - negative balance";
}
