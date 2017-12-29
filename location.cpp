#include "location.h"
#include <stdio.h>

void Location::generateLocation(int x,int y,Player *player)
{
    this-> x = x-1;
    this-> y = y-1;
    Field ***area = new Field **[x];
    for(int i=0 ; i < x; i++)
    {
        area[i] = new Field* [y];
        for(int j=0; j < y; j++)
        {
           area[i][j] = new Field(player);
        }

    }
        p = area;
}

Field*** Location::getArea()
{
    return p;
}


int Location::getX()
{
    return x;
}

int Location::getY()
{
    return y;
}

Location::Location(int x, int y,Player *player)
{
    this -> player = player;
    generateLocation(x,y,player);
}
