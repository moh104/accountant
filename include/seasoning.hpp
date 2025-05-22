#ifndef SEASONING_H
#define SEASONING_H

#include "item.hpp"

class Seasoning : public Item
{
    private:
        int qualityRating;

        std::ostream& utilityPrint(std::ostream &) const noexcept override;

    public:
        Seasoning(const std::string & , USD , int , int);

        void setQualityRating(int);

        [[nodiscard]] int getQualityRating() const noexcept;
};

#endif