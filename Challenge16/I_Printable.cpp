#include "I_Printable.h"
#include "Savings_Account.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}