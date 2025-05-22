#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "usd.hpp"

class Item
{
    private:
        std::string name;
        USD price;
        int inventory;
        std::string unit; // Using string is better than enum because it is easier to maintain and avoids additional conversions (because we don't need special processing)
        int soldCount = 0;
        unsigned int discount = 0;
        
    public:
        Item(const std::string& , const USD& , int , const std::string &);
        virtual std::ostream &utilityPrint(std::ostream&) const noexcept;

        void setSoldCount(int);
        void setName(const std::string &);
        void setPrice(const USD&);
        void setInventory(int);
        void setUnit(const std::string &);

        [[nodiscard]] const std::string& getName() const noexcept;
        [[nodiscard]] int getSoldCount() const noexcept;
        [[nodiscard]] USD getPrice() const noexcept;
        [[nodiscard]] unsigned int getInventory() const noexcept;
        [[nodiscard]] const std::string& getUnit() const noexcept;
        [[nodiscard]] unsigned int getDiscount() const noexcept;

        Item& operator++();

        virtual ~Item() noexcept = default;
};

std::ostream & operator<<(std::ostream& , const Item&);

#endif