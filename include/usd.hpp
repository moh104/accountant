#ifndef USD_H
#define USD_H

#include "currency.hpp"
#include "eur.hpp"
#include "irr.hpp"

class USD : public Currency
{
    public:
        explicit USD(double);
        explicit USD(const Currency&);

        std::shared_ptr<Currency> newInstance() const override;

        std::string getUnit() const noexcept override;
};

#endif