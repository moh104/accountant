#include <stdexcept>
#include "irr.hpp"
#include "usd.hpp"

using namespace std;

IRR::IRR(double amount) : Currency(amount) {}

IRR::IRR(const USD& i_USD) : Currency(i_USD.getAmount() * rateUSDToIRR) {}

shared_ptr<Currency> IRR::newInstance() const
{
    return make_shared<IRR>(*this);
}

std::string IRR::getUnit() const noexcept
{
    return "IRR";
}