#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance}
{
}

// Withdraw:
//      Every withdrawal transaction will be assessed pervious mentioned flat fee

bool Checking_Account::withdraw(double amount)
{
    amount += fee;
    return Account::withdraw(amount);
}