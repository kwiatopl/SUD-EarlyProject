#pragma once
#include "creature.h"
#include "location.h"

class Location;
class Player : public Creature
{
private:
    int mp, exp, coordinateX, coordinateY, maxHp, maxMp, multiplier;
    Location *actualLocation;
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

public:
    int mpCount,hpCount;
    void useHpPotion();
    void useMpPotion();
    void movePlayer(int x);
    void levelUp();
    int getMaxHp();
    int getMaxMp();
    int getMp();
    int getExp();
    int getCoordinateX();
    int getCoordinateY();
    void setActualLocation(Location *actualLocation);
    void setMp(int val);
    void setMaxHp(int val);
    void setMaxMp(int val);
    void setExp(int val);
    void setCoordinates(int x, int y);
    Player();
};

