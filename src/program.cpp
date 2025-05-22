#include <iostream>
#include "program.hpp"
#include "eur.hpp"
#include "irr.hpp"
#include "fruit.hpp"
#include "snack.hpp"
#include "seasoning.hpp"

using namespace std;

int Program::get_intNumber(const string& output)
{
    string input;
    int value;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos = 0;
            value = stoi(input , &pos);

            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a integer number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid integer number.\n";
        }
    }
}

double Program::get_doubleNumber(const string& output)
{
    string input;
    double value;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos = 0;
            value = stod(input , &pos);

            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a integer number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid integer number.\n";
        }
    }
}

void Program::setCart()
{
    string name;
    string balanceType;
    int buyerAccountNum;
    int storeAccountNum;
    double balance;
    
    
    cout << "Enter Buyer Name: ";
    getline(cin , name);
    buyerAccountNum = get_intNumber("Enter Buyer Account Number: ");
    balance = get_doubleNumber("Enter Buyer Initial Balance: ");
    BankAccount buyerAccount(name , buyerAccountNum , AccountType::PERSONAL , make_shared<USD>(0));
    while (true)
    {
        cout << "Write the currency type of the bank account in capital letters (USD , EUR , IRR): ";
        getline(cin , balanceType);
        if (balanceType == "USD")
        {
            buyerAccount.set_balance(make_shared<USD>(balance));
            break;
        }
        else if (balanceType == "EUR")
        {
            buyerAccount.set_balance(make_shared<EUR>(balance));
            break;
        }
        else if (balanceType == "IRR")
        {
            buyerAccount.set_balance(make_shared<IRR>(balance));
            break;
        }
        else
        {
            cerr << "Invalid bank account currency type entered. Please try again.\n";
        }
    }

    cout << "Enter Store Name: ";
    getline(cin, name);
    while (true)
    {
        storeAccountNum = get_intNumber("Enter Store Account Number: ");
        if (storeAccountNum != buyerAccountNum)
        {
            break;
        }
        cerr << "Account numbers must be different. Please try again.\n";
    }
    balance = get_doubleNumber("Enter store Initial Balance: ");
    BankAccount storeAccount(name , storeAccountNum , AccountType::ORGANIZATION , make_shared<USD>(0));
    while (true)
    {
        cout << "Write the currency type of the bank account in capital letters (USD , EUR , IRR):";
        getline(cin , balanceType);
        if (balanceType == "USD")
        {
            storeAccount.set_balance(make_shared<USD>(balance));
            break;
        }
        else if (balanceType == "EUR")
        {
            storeAccount.set_balance(make_shared<EUR>(balance));
            break;
        }
        else if (balanceType == "IRR")
        {
            storeAccount.set_balance(make_shared<IRR>(balance));
            break;
        }
        else
        {
            cerr << "Invalid bank account currency type entered. Please try again.\n";
        }
    }

    cart = new ShoppingCart(buyerAccount , storeAccount);
}

void Program::setInventory()
{
    int count = get_intNumber("Enter number of items in store inventory: ");
    if (count < 0)
    {
        throw invalid_argument("The numbers of items can not be negative.");
    }

    int choiceItemType;
    string name;
    double price;
    int numOfInventory;

    inventory.clear();
    for (int i = 0; i < count; ++i)
    {
        choiceItemType = get_intNumber("\nChoose number of item type (1-Fruit , 2-Snack , 3-Seasoning): ");
        cout << "Enter name: ";
        getline(cin, name);
        price = get_doubleNumber("Enter price (USD):");
        numOfInventory = get_intNumber("Enter the stock of this item in the store: ");
        if (choiceItemType == 1)
        {
            while (true)
            {
                string choice;
                cout << "Is it greenhouse fruit? (YES / NO): ";
                getline(cin , choice);
                if (choice == "YES")
                {
                    inventory.push_back(new Fruit(name, USD(price), numOfInventory, true));
                    break;
                }
                else if (choice == "NO")
                {
                    inventory.push_back(new Fruit(name, USD(price), numOfInventory, false));
                    break;
                }
                else
                {
                    cerr << "The answer to the question must be YES / NO only. Please try again.\n";
                }
            }
        }
        else if (choiceItemType == 2)
        {
            inventory.push_back(new Snack(name , USD(price) , numOfInventory , get_doubleNumber("Enter package weight (g): ")));
        }
        else if (choiceItemType == 3)
        {
            inventory.push_back(new Seasoning(name, USD(price), numOfInventory, get_intNumber("Enter seasoning quality rating [1 , 10]: ")));
        }
        else
        {
            cout << "Invalid item type!\n";
            --i;
        }
    }
}

void Program::menu() const noexcept
{
    cout << "\n----COMMAND MENU----\n";
    cout << "1) Show Store Inventory\n";
    cout << "2) Add Item to Cart\n";
    cout << "3) Remove Item from Cart\n";
    cout << "4) Show Shopping Cart\n";
    cout << "5) Final transaction\n";
    cout << "6) Show menu\n";
    cout << "7) Show buyer bank account information\n";
    cout << "8) Exit\n";
}

void Program::displayInventory() const
{
    cout << "\n-----STORE INVENTORY-----\n";
    if (inventory.empty())
    {
        cout << "No items available in the store.\n";
        return;
    }

    for (size_t i = 0; i < inventory.size(); ++i)
    {
        cout << i + 1 << ") " << inventory[i]->getName() << " Inventory -> " << inventory[i]->getInventory() << " price ->" << inventory[i]->getPrice().getAmount() <<  "$" << "\n";
    }
}

Item* Program::getItem(size_t index)
{
    if (index < 1 || index > inventory.size())
    {
        throw invalid_argument("Invalid item selection.");
    }
    return inventory[index - 1];
}