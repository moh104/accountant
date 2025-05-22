#include <stdexcept>
#include "eur.hpp"
#include "usd.hpp"

using namespace std;

EUR::EUR(double amount) : Currency(amount) {}

EUR::EUR(const USD& i_USD) : Currency(i_USD.getAmount() * rateUSDToEUR) {}

shared_ptr<Currency> EUR::newInstance() const
{
    return make_shared<EUR>(*this);
}

std::string EUR::getUnit() const noexcept
{
    return "EUR";
}