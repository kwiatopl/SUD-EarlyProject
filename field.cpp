#include "field.h"
#include "stdlib.h"

Event* Field::getEvent()
{
    return event;
}

Field::Field(Player *player)
{
    event = new Event(player);
}
