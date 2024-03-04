#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance}
{
}

/* The Trust account deposit works just like a savings account deposit.
    However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.

    The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
    You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)*/

bool Trust_Account::deposit(double amount)
{
    if (amount >= 5000)
    {
        amount += 50;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if (amount >= (20 * balance / 100) || counter >= 3)
    {
        return 0;
    }
    counter++;
    return Savings_Account::withdraw(amount);
}
