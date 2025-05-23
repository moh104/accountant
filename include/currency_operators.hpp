#ifndef CURRENCY_OPERATORS_H
#define CURRENCY_OPERATORS_H

#include "currency.hpp"
#include "usd.hpp"

USD operator+(const Currency& , const Currency&);
USD operator-(const Currency& left , const Currency& right);
USD operator*(const Currency& left , double right);
USD operator/(const Currency& left , double right);

#endif