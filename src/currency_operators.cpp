#include "currency_operators.hpp"

USD operator+(const Currency& left , const Currency& right)
{
    return USD(static_cast<USD>(left).getAmount() + static_cast<USD>(right).getAmount());
}

USD operator-(const Currency& left , const Currency& right)
{
    return USD(static_cast<USD>(left).getAmount() - static_cast<USD>(right).getAmount());
}

USD operator*(const Currency& left , double right)
{
    return USD(static_cast<USD>(left).getAmount() * right);
}

USD operator/(const Currency& left , double right)
{
    if (right == 0)
    {
        throw std::invalid_argument("Division by zero");
    }

    return USD(static_cast<USD>(left).getAmount() / right);
}