#include "creature.h"

Creature::Creature()
{
}

void Creature::setDefence(int defence)
{
    this -> defence = defence;
}

void Creature::setAttack(int attack)
{
    this -> attack = attack;
}

void Creature::setHp(int hp)
{
    this -> hp = hp;
}

void Creature::setLvl(int lvl)
{
    this -> lvl = lvl;
}

int Creature::getDefence()
{
    return defence;
}

int Creature::getAttack()
{
    return attack;
}

int Creature::getHp()
{
    return hp;
}

int Creature::getLvl()
{
    return lvl;
}
