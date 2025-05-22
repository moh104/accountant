#include <vector>
#include "item.hpp"
#include "shoppingcart.hpp"

class Program
{
    private:
        std::vector<Item*> inventory;
        ShoppingCart* cart;

        int get_intNumber(const std::string&);
        double get_doubleNumber(const std::string&);
        void displayInventory() const;
        Item* getItem(size_t index);
        void setCart();
        void setInventory();
        void menu() const noexcept;

    public:
        Program();
        void run();
        ~Program();
};