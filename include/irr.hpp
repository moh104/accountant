#ifndef IRR_H
#define IRR_H

#include "currency.hpp"

class IRR : public Currency
{
    public:
        static constexpr double rateUSDToIRR = 840650;

        explicit IRR(double);
        explicit IRR(const USD&);

        std::shared_ptr<Currency> newInstance() const override;

        std::string getUnit() const noexcept override;
};

#endif
