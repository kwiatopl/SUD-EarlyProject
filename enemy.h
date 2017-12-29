#pragma once
#include "creature.h"
#include <string>

class Enemy : public Creature
{
private:
    std::string name;
public:
    void setName(int name);
    std::string getName();
    Enemy(std::string name, int hp, int attack, int defence, int lvl);
};

