#include "bankaccount.hpp"
#include "currency_operators.hpp"
#include "eur.hpp"
#include "irr.hpp"
#include <iostream>

using namespace std;

BankAccount::BankAccount(const string& holder_name, int account_number , AccountType account_type, std::shared_ptr<Currency> balance)
{
    set_holder_name(holder_name);
    set_account_number(account_number);
    set_balance(balance);
    set_account_type(account_type);
}

void BankAccount::deposit(const Currency& i_currency)
{
    if (i_currency.getAmount() <= 0) {
        throw invalid_argument("The deposited amount must be positive.");
    }

    if (balance->getUnit() == "USD")
    {
        (*balance) = (*balance) + i_currency;
    }
    else if (balance->getUnit() == "EUR")
    {
        (*balance) = EUR((*balance) + i_currency);
    }
    else if (balance->getUnit() == "IRR")
    {
        (*balance) = IRR((*balance) + i_currency);
    }
}

void BankAccount::withdraw(const Currency& i_currency)
{
    reset_daily_transfer();

    if (i_currency.getAmount() <= 0 ||*balance < i_currency)
    {
        throw invalid_argument("The amount of currency to be withdrawn must be within the range of (0 , balance].");
    }

    if (balance->getUnit() == "USD")
    {
        if ((USD(daily_transferred) + i_currency) > USD(daily_limit))
        {
            throw invalid_argument("Transcation is outside the daily limit.");
        }

        (*balance) = (*balance) - i_currency;
        daily_transferred += USD(i_currency).getAmount();
    }
    else if (balance->getUnit() == "EUR")
    {
        if ((EUR(daily_transferred) + i_currency) > EUR(daily_limit))
        {
            throw invalid_argument("Transcation is outside the daily limit.");
        }

        (*balance) = EUR((*balance) - i_currency);
        daily_transferred += EUR(static_cast<USD>(i_currency)).getAmount();
    }
    else if (balance->getUnit() == "IRR")
    {
        if ((IRR(daily_transferred) + i_currency) > IRR(daily_limit))
        {
            throw invalid_argument("Transcation is outside the daily limit.");
        }

        (*balance) = IRR((*balance) - i_currency);
        daily_transferred += IRR(static_cast<USD>(i_currency)).getAmount();
    }
}

string BankAccount::get_holder_name() const
{
    return holder_name;
}

int BankAccount::get_account_number() const
{
    return account_number;
}

AccountType BankAccount::get_account_type() const
{
    return type;
}

string BankAccount::get_balance() const
{
    string result = to_string(balance->getAmount()) + " " + balance->getUnit();
    return result;
}

void BankAccount::set_holder_name(const std::string& i_name)
{
    if (i_name.empty())
    {
        throw std::invalid_argument("Holder name cannot be empty.");
    }
    holder_name = i_name;
}

void BankAccount::set_account_number(int i_number)
{
    if (i_number < 0)
    {
        throw std::invalid_argument("Account number cannot be negative.");
    }
    account_number = i_number;
}

void BankAccount::reset_daily_transfer()
{
    time_t now = time(0);
    tm* localTime = localtime(&now);
    static int day = localTime->tm_mday;

    if (localTime->tm_mday != day)
    {
        daily_transferred = 0.0;
        day = localTime->tm_mday;
    }
}

void BankAccount::set_account_type(AccountType i_type)
{
    type = i_type;
    if (balance->getUnit() == "USD")
        daily_limit = (i_type == AccountType::PERSONAL) ? USD(1000.0).getAmount() : USD(10000.0).getAmount();

    else if (balance->getUnit() == "IRR")
        daily_limit = (i_type == AccountType::PERSONAL) ? IRR(USD(1000.0)).getAmount() : IRR(USD(10000.0)).getAmount();

    else if (balance->getUnit() == "EUR")
        daily_limit = (i_type == AccountType::PERSONAL) ? EUR(USD(1000.0)).getAmount() : EUR(USD(10000.0)).getAmount();
}

void BankAccount::set_balance(std::shared_ptr<Currency> i_balance)
{
    if (!i_balance)
    {
        throw invalid_argument("Invalid balance entered.");
    }
    balance = (*i_balance).newInstance();
}