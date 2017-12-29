#include "mppotion.h"

void MpPotion::effect()
{
    int x = target -> getMp() + 20;
    target -> setMp(x);
}

MpPotion::MpPotion(Player *target)
{
    this -> target = target;
}

MpPotion::~MpPotion()
{
}
