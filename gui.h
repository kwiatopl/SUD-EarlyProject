#pragma once
#include "player.h"
#include "fight.h"
#include "location.h"
#include "enemy.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include "location.h"
using namespace std;

class Location;
class Fight;
class Player;
class GUI
{
    private:
        Player *player;
        Fight *fight;
        Location *location;
        bool flag;
        void keyPressed();
        int locationX, locationY;
    public:
        void drawMap();
        void levelUp();
        void render();
        GUI(Player *player, Location *location);
};
