#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "item.hpp"

using namespace std;

ostream & operator<<(ostream& outPut , const Item& item)
{
    return item.utilityPrint(outPut);
}

Item::Item(const string& i_name , const USD& i_price , int i_inventory , const string &i_unit) : price(0.0)
{
    setName(i_name);
    setPrice(i_price);
    setInventory(i_inventory);
    setUnit(i_unit);
}

ostream & Item::utilityPrint(ostream& outPut) const noexcept
{
    outPut<< left << setw(8) << name << " $" << setw(10) << getPrice().getAmount()
        << " per " << setw(8) << getUnit() << " ((Quantity ---> " << setw(3) << getSoldCount() << ' ' << getUnit() << "))";

    return outPut;
}

void Item::setName(const std::string &i_name)
{
    if(i_name.empty())
    {
        throw invalid_argument("Name cannot be empty.");
    }
    if (i_name.size() > 8)
    {
        cout << "Only the first 8 characters are saved.\n";
        name = i_name.substr(0 , 8);
        return;
    }
    name = i_name;
}

void Item::setPrice(const USD& i_price)
{
    if(i_price.getAmount() < 0.0)
    {
        throw invalid_argument("Price cannot be negative.");
    }
    price = i_price;
}

void Item::setInventory(int i_inventory)
{
    if(i_inventory < 0)
    {
        throw invalid_argument("Inventory cannot be negative.");
    }
    inventory = i_inventory;
}

void Item::setUnit(const std::string &i_unit)
{
    if(i_unit == "kg" || i_unit == "g" || i_unit == "package")
    {
        unit = i_unit;
    }
    else
    {
        throw invalid_argument("Invalid unit type. Use 'kg', 'g', or 'package' in lowercase.");
    }
}

const std::string& Item::getName() const noexcept
{
    return name;
}

unsigned int Item::getSoldCount() const noexcept
{
    return soldCount;
}
USD Item::getPrice() const noexcept
{
    return price;
}
unsigned int Item::getInventory() const noexcept
{
    return inventory;
}
const std::string& Item::getUnit() const noexcept
{
    return unit;
}

unsigned int Item::getDiscount() const noexcept
{
    return discount;
}

Item& Item::operator++()
{
    if(getInventory() < 1)
    {
        throw invalid_argument("Item out of stock.");
    }
    ++soldCount;
    
    setInventory(getInventory() - 1); //This is because accessing member data only with set and get functions reduces the problems of changing the code.   
    
    if((soldCount % 5) == (soldCount/5 - 1))
    {
        if(getInventory() < 1)
        {
            cerr << "Your discount cannot be calculated due to lack of inventory.";
            return *this;
        }
        ++soldCount;
        ++discount;
        setInventory(getInventory() - 1);
    }

    return *this;
}