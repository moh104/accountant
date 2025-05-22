#include <iostream>
#include <iomanip>
#include "fruit.hpp"

using namespace std;

std::ostream& Fruit::utilityPrint(ostream& outPut) const noexcept
{
    outPut << "----------";
    outPut << left << setw(10) << "Fruit:\n";
    Item::utilityPrint(outPut) << "   [Cultivation type -> " << (getIsGreenHouse() ?  "GreenHouse" : "Natural") << "]\n";
    return outPut;
}

Fruit::Fruit(const string& i_name , USD i_price , int i_inventory , bool i_isGreenHouse) : Item(i_name , i_price , i_inventory , "kg")
{
    setIsGreenHouse(i_isGreenHouse);
}

void Fruit::setIsGreenHouse(bool i_isGreenHouse) noexcept
{
    isGreenHouse = i_isGreenHouse;
}

[[nodiscard]] bool Fruit::getIsGreenHouse() const noexcept
{
    return isGreenHouse;
}