#include <iostream>
#include "Inventory.h"
#include "Item.h"

int main()
{
    std::cout << SlotsUsed(4) << "\n";
    std::cout << SlotsFree(4) << "\n";

    Item sword;
    sword.weight = 5;
    std::cout << sword.weight << "\n";

    return 0;
}