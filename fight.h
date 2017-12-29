#pragma once
#include "player.h"
#include "enemy.h"
#include "gui.h"
#include <conio.h>
#include <cstdlib>

class Player;
class Enemy;
class Fight
{
private:
    Player *player;
    Enemy *enemy;
    bool enemyTurn,playerTurn,deathOfPlayer;
public:
    void turnBasedSystem();
    void normalAttackPlayer(Player *player, Enemy *enemy);
    void magicAttackPlayer(Player *player, Enemy *enemy);
    void normalAttackEnemy(Enemy *enemy, Player *player);
    void heavyAttackEnemy(Enemy *enemy, Player *player);
    bool getDeathOfPlayer();
    Fight(Player *player, Enemy *enemy);
};

