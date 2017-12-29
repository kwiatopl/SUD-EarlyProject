#pragma once
#include "item.h"
#include "player.h"

class Player;
class MpPotion : public Item
{
private:
    Player *target;
public:
    void effect();
    MpPotion(Player *target);
    ~MpPotion();
};

