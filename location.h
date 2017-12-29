#pragma once
#include "field.h"
#include "player.h"

class Player;
class Field;
class Location
{
private:
    Player *player;
    Field ***p;
    int x,y;
    void generateLocation(int x,int y,Player *player);
public:
    int getX();
    int getY();
    Field ***getArea();
    Location(int x, int y,Player *player);
};


