#ifndef FRUIT_H
#define FRUIT_H

#include "item.hpp"

class Fruit : public Item
{
    private:
        bool isGreenHouse;

        std::ostream& utilityPrint(std::ostream&) const noexcept override;

    public:
        Fruit(const std::string& i_name , USD i_price , int i_inventory , bool i_isGreenHouse);

        void setIsGreenHouse(bool) noexcept;

        [[nodiscard]] bool getIsGreenHouse() const noexcept;
};

#endif
