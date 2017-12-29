#pragma once
#include <limits>
class Creature
{
private:
    int hp, attack, defence, lvl;
public:
    int getHp();
    int getAttack();
    int getDefence();
    int getLvl();
    void setHp(int hp);
    void setAttack(int attack);
    void setDefence(int defence);
    void setLvl(int lvl);
    Creature();
};

