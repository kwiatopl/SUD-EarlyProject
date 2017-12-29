#pragma once
#include "event.h"
#include "player.h"

class Player;
class Event;
class Field
{
private:
    Event *event;
public:
    Event* getEvent();
    Field(Player *player);
};

