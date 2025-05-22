#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "Item.hpp"
#include "bankaccount.hpp"

class ShoppingCart
{
    private:
        std::vector<Item*> items;
        BankAccount buyerAccount;
        BankAccount storeAccount;

        USD calTotalPrice() const noexcept;

    public:
        ShoppingCart(const BankAccount& , const BankAccount&);

        void showBankAccount() const noexcept;
        void addItem(Item*);
        void removeItem(const std::string&);
        void makeTran();
        void print() const noexcept;
};

#endif