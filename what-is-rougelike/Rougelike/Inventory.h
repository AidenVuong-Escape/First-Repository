#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"

int TotalWeight(int itemCount);

int SlotsUsed(int items);
int SlotsFree(int items);

#endif