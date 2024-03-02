#include "InsufficentFundsException.h"

std::string InsufficentFundsException::what() const
{
    return "The withdraw results in a negative balance";
}
