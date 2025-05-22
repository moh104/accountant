#include "usd.hpp"

using namespace std;

USD::USD(double amount) : Currency(amount) {}

USD::USD(const Currency& i_currency) : Currency(i_currency.getUnit() == "EUR" ? (i_currency.getAmount() / EUR::rateUSDToEUR) : (i_currency.getUnit() == "IRR" ? (i_currency.getAmount() / IRR::rateUSDToIRR) : i_currency.getAmount())) {}

shared_ptr<Currency> USD::newInstance() const
{
    return make_shared<USD>(*this);
}

string USD::getUnit() const noexcept
{
    return "USD";
}