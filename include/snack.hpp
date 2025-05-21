#ifndef SNACK_H
#define SNACK_H

#include "item.hpp"

class Snack : public Item
{
    private:
        double packageWeight;

        std::ostream& utilityPrint(std::ostream &) const noexcept override;

    public:
        Snack(const std::string & , USD , int , double);

        void setPackageWeight(double);

        [[nodiscard]] double getPackageWeight() const noexcept;
};

#endif