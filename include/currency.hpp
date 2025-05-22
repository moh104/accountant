#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>
#include <memory>

class USD;

class Currency
{
private:
    double amount;

public:
    explicit Currency(double);

    virtual std::shared_ptr<Currency> newInstance() const = 0;

    void setAmount(double);
    
    virtual std::string getUnit() const noexcept = 0;
    double getAmount() const noexcept;

    bool operator==(const Currency&) const noexcept;
    bool operator!=(const Currency&) const noexcept;
    bool operator<(const Currency&) const noexcept;
    bool operator>(const Currency&) const noexcept;

    virtual ~Currency() = default;
};

#endif
