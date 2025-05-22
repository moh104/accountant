#include <stdexcept>
#include "Currency.hpp"
#include "usd.hpp"

Currency::Currency(double i_amount)
{
    setAmount(i_amount);
}

void Currency::setAmount(double i_amount)
{
    if (i_amount < 0)
    {
        throw std::invalid_argument("The amount of currency cannot be negative.");
    }
    amount = i_amount;
}

double Currency::getAmount () const noexcept
{
    return amount;
}

bool Currency::operator==(const Currency& other) const noexcept
{
    return static_cast<USD>(*this).getAmount() == static_cast<USD>(other).getAmount();
}

bool Currency::operator!=(const Currency& other) const noexcept
{
    return !(*this == other);
}

bool Currency::operator<(const Currency& other) const noexcept
{
    return static_cast<USD>(*this).getAmount() < static_cast<USD>(other).getAmount();
}

bool Currency::operator>(const Currency& other) const noexcept
{
    return static_cast<USD>(*this).getAmount() > static_cast<USD>(other).getAmount();
}