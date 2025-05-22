#include <iomanip>
#include "shoppingcart.hpp"
#include "currency_operators.hpp"
#include "item.hpp"

using namespace std;

ShoppingCart::ShoppingCart(const BankAccount& i_buyerAccount, const BankAccount& i_storeAccount) : buyerAccount(i_buyerAccount), storeAccount(i_storeAccount)
{
    if (buyerAccount.get_account_type() == AccountType::ORGANIZATION)
    {
        throw invalid_argument("The buyer's bank account must be 'PERSONAL'.");
    }
    if (storeAccount.get_account_type() == AccountType::PERSONAL)
    {
        throw invalid_argument("The store's bank account must be 'ORGANIZATION'.");
    }
}

void ShoppingCart::addItem(Item* i_item)
{
    for (auto & item : items)
    {
        if (item->getName() == i_item->getName())
        {
            ++(*item);
            return;
        }
    }

    items.push_back(i_item);
    i_item->setInventory(i_item->getInventory() - 1);
    i_item->setSoldCount(i_item->getSoldCount() + 1);
}

void ShoppingCart::removeItem(const std::string& i_name)
{
    for (auto it = items.begin() ; it != items.end() ; ++it)
    {
        if ((*it)->getName() == i_name)
        {
            (*it)->setInventory((*it)->getInventory() + (*it)->getSoldCount());
            (*it)->setSoldCount(0);
            items.erase(it);
            return;
        }
    }

    throw invalid_argument("There is no such item.");
}

USD ShoppingCart::calTotalPrice() const noexcept
{
    USD total = USD(0);
    for (const auto& item : items)
    {
        total = total + (item->getPrice() * (item->getSoldCount() - item->getDiscount()));
    }

    return total;
}

void ShoppingCart::makeTran()
{
    buyerAccount.withdraw(calTotalPrice());
    storeAccount.deposit(calTotalPrice());
    cout << "SUCCESSFUL PURCHASE\n";
    print();
    items.clear();
}

void ShoppingCart::print() const noexcept
{
    if (items.empty())
    {
        cout << "Shopping Cart is empty.\n";
        return;
    }

    cout << "--------------------------------------------------\n";
    cout << "RECEIPT:\n";

    for (const auto& item : items)
    {
        cout << (*item) << "\n";
    }

    cout << "-----------------\n";
    cout << "TOTAL PRICE: $" << calTotalPrice().getAmount() << "\n";
    cout << "-----------------\n";
}

void ShoppingCart::showBankAccount() const noexcept
{
    cout << "name: " << buyerAccount.get_holder_name() << "  account type: " << (buyerAccount.get_account_type() == AccountType::ORGANIZATION ? "Organization" : "Personal")
        << "  account numer: " << buyerAccount.get_account_number() << "  balance: " << buyerAccount.get_balance() << '\n';
}