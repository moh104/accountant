#include <iostream>
#include <iomanip>
#include "snack.hpp"

using namespace std;

ostream& Snack::utilityPrint(ostream &outPut) const noexcept
{
    outPut << "----------";
    outPut  << left << setw(10) << "Snack:\n";
    Item::utilityPrint(outPut) << "   [Weight of each package -> " << getPackageWeight() << " g]\n";
    return outPut;
}

Snack::Snack(const string &i_name , USD i_price , int i_inventory , double i_packageWeight)
    : Item(i_name , i_price , i_inventory , "package")
{
    setPackageWeight(i_packageWeight);
}

void Snack::setPackageWeight(double i_weight)
{
    if(i_weight <= 0.0)
    {
        throw invalid_argument("Package weight must be positive.");
    }
    packageWeight = i_weight;
}

double Snack::getPackageWeight() const noexcept
{
    return packageWeight;
}