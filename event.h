#pragma once
#include <stdio.h>
#include <cstdlib>
#include "fight.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "mppotion.h"
#include "hppotion.h"
#include <string>
#include <cstdlib>

class Player;
class Event
{
private:
    Player *player;
    bool triggered;
    int hp, level, attack, defence;
    std::string name;
public:
    std::string randName();
    void launch();
    void adjust();
    Event(Player *player);
};
