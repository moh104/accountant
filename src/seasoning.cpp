#include <iostream>
#include <iomanip>
#include "seasoning.hpp"

using namespace std;

ostream& Seasoning::utilityPrint(ostream &outPut) const noexcept
{
    outPut<< "----------";
    outPut  << left << setw(10) << "Seasoning:\n";
    Item::utilityPrint(outPut) << "   [Spice quality rate -> " << getQualityRating() << "]\n";
    return outPut;
}

Seasoning::Seasoning(const string &i_name , USD i_price , int i_inventory , int i_qualityRating)
    : Item(i_name , i_price , i_inventory , "g")
{
    setQualityRating(i_qualityRating);
}

void Seasoning::setQualityRating(int i_qualityRating)
{
    if(i_qualityRating < 1 || i_qualityRating > 10)
    {
        throw invalid_argument("The spice quality rating must be a number between 1 and 10.");
    }
    qualityRating = i_qualityRating;
}

int Seasoning::getQualityRating() const noexcept
{
    return qualityRating;
}