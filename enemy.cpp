#include "enemy.h"

std::string Enemy::getName()
{
    return name;
}

void Enemy::setName(int name)
{
    this -> name = name;
}

Enemy::Enemy(std::string name,int hp, int attack, int defence, int lvl)
{
    this->name=name;
    this->setHp(hp);
    this->setAttack(attack);
    this->setDefence(defence);
    this->setLvl(lvl);
}
