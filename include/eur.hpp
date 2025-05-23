#ifndef EUR_H
#define EUR_H

#include "currency.hpp"

class EUR : public Currency
{
    public:
        static constexpr double rateUSDToEUR = 0.88;

        explicit EUR(double);
        explicit EUR(const USD&);

        std::shared_ptr<Currency> newInstance() const override;
        
        std::string getUnit() const noexcept override;
};

#endif
