#pragma once
#include "item.h"
#include "player.h"

class Player;
class HpPotion : public Item
{
private:
    Player *target;
public:
    void effect();
    HpPotion(Player *target);
    ~HpPotion();
};
