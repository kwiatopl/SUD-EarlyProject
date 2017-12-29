#include "hppotion.h"

void HpPotion::effect()
{
    int x = target -> getHp() + 20;
    target -> setHp(x);
}

HpPotion::HpPotion(Player *target)
{
    this -> target = target;
}

HpPotion::~HpPotion()
{

}
