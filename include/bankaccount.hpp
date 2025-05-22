#ifndef BANCKACCOUNT_H
#define BANCKACCOUNT_H

#include <string>
#include <memory>
#include "currency.hpp"

enum class AccountType {
    PERSONAL,
    ORGANIZATION
};

class BankAccount {
private:
    std::string holder_name; 
    int account_number;
    AccountType type;
    std::shared_ptr<Currency> balance;
    double daily_limit;
    double daily_transferred = 0.0;

    void reset_daily_transfer();

public:
    BankAccount(const std::string& , int , AccountType , std::shared_ptr<Currency>);

    void deposit(const Currency& i_currency);
    void withdraw(const Currency& i_currency);

    std::string get_holder_name() const;
    int get_account_number() const;
    AccountType get_account_type() const;
    std::string get_balance() const;

    void set_holder_name(const std::string&);
    void set_account_number(int);
    void set_account_type(AccountType);
    void set_balance(std::shared_ptr<Currency>);
};

#endif