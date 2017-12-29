#include "fight.h"


int operator-(Player &player, Enemy &enemy)
{
    int level = player.getLvl();
    float multiplier = level * 0.1;
    float defence = enemy.getDefence() * 0.01;
    int attack = (player.getAttack()) * multiplier - defence;
    int dmg = enemy.getHp() - attack;
    return dmg;
}

int operator*(Player &player, Enemy &enemy)
{
    int level = player.getLvl();
    float multiplier = level * 0.1;
    float defence = enemy.getDefence() * 0.005;
    int attack = (player.getAttack()) * multiplier - defence;
    int dmg = enemy.getHp() - attack;
    return dmg;
}

int operator-(Enemy &enemy, Player &player)
{
    int level = enemy.getLvl();
    float multiplier = level * 0.05;
    float defence = player.getDefence() * 0.01;
    int attack = (enemy.getAttack()) * multiplier - defence;
    int dmg = player.getHp() - attack;
    return dmg;
}

int operator*(Enemy &enemy, Player &player)
{
    int level = enemy.getLvl();
    float multiplier = level * 0.1;
    float defence = player.getDefence() * 0.005;
    int attack = (enemy.getAttack()) * multiplier - defence;
    int dmg = player.getHp() - attack;
    return dmg;
}

void Fight::magicAttackPlayer(Player *player, Enemy *enemy)
{
    if (player -> getMp() <= 0)
    {
        printf("\nZA MALO MANY!\n");
        printf("RZUCANIE CZARU NIE POWIODLO SIE!\n");
    }
    else
    {
        player -> setMp(player -> getMp() - 20);
        enemy -> setHp(*player * *enemy);
        if (enemy -> getHp() <= 0)
        {
            enemy -> setHp(0);
        }
        printf ("\nPOZOSTALA MANA GRACZA: %d\n", player -> getMp());

    };
}


void Fight::normalAttackPlayer(Player *player, Enemy *enemy)
{
    enemy -> setHp(*player - *enemy);
    if (enemy -> getHp() <= 0)
    {
        enemy -> setHp(0);
    }
}

void Fight::normalAttackEnemy(Enemy *enemy, Player *player)
{
    player -> setHp(*enemy - *player);
    if (player -> getHp() <= 0 )
    {
        player -> setHp(0);
        printf ("\nPORAZKA!\n");
        deathOfPlayer = true;
    }
}

void Fight::heavyAttackEnemy(Enemy *enemy, Player *player)
{
    player -> setHp(*enemy * *player);
    if (player -> getHp() < 0 )
    {
        player -> setHp(0);
        printf ("\nPORAZKA!\n");
        deathOfPlayer = true;
    }
}

void Fight::turnBasedSystem()
{
int random;
unsigned int x = 0;
int playerTurn = true;
int enemyTurn = false;
printf ("\nNAPOTYKASZ PRZECIWNIKA: %s\n", enemy -> getName().c_str());
printf ("\nHP GRACZA : %d   MP GRACZA: %d\nHP WROGA: %d\n", player -> getHp(),player -> getMp(), enemy -> getHp());
while (player -> getHp() > 0 || enemy -> getHp() > 0 )
{
    while(playerTurn)
    {
        printf("\n[1] ZWYKLY ATAK\n[2] MAGICZNY ATAK\n[m] UZYJ MANA POTION\n[h] UZYJ HP POTION\n");
        x = getch();
        if (x != 49 && x!= 50 && x!= 104 && x!= 109)
        {
            printf ("\nBLEDNY KLAWISZ\n");
        };
        if(x == 49)
        {
            normalAttackPlayer(player, enemy);
            printf ("\nHP GRACZA : %d   MP GRACZA: %d\nHP WROGA: %d\n", player -> getHp(),player -> getMp(), enemy -> getHp());
        }
        if(x == 50)
        {
            magicAttackPlayer(player, enemy);
            printf ("\nHP GRACZA : %d   MP GRACZA: %d\nHP WROGA: %d\n", player -> getHp(),player -> getMp(), enemy -> getHp());
        }
        if(x == 109)
        {
            if(player -> mpCount > 0)
            {
                player -> useMpPotion();
            }
            else
            {
                printf("\nBRAK MP POTION\n");
            }
        }
        if(x == 104)
        {
            if(player -> hpCount > 0)
            {
                player -> useHpPotion();
            }
            else
            {
                printf("\nBRAK HP POTION\n");
            }
        }
        playerTurn = false;

    };
        if (x == 49 || x == 50)
        {
            enemyTurn = true;

            if(enemy -> getHp() <= 0)
            {
                printf("\nPRZECIWNIK POKONANY!\n");
                player -> setExp(player -> getExp() + 50);
                printf("\nEXP +50\nPOZOSTALE HP GRACZA: %d\n", player -> getHp());
                break;
            }
            else
            {
                while(enemyTurn)
                {
                    random = (rand()%11);
                    if (random <= 8)
                    {
                        printf ("\nNORMALNY ATAK WROGA\n");
                        normalAttackEnemy(enemy,player);
                        if(deathOfPlayer)
                        {
                            break;
                        }
                        printf ("\nHP GRACZA : %d   MP GRACZA: %d\nHP WROGA: %d\n", player -> getHp(),player -> getMp(), enemy -> getHp());
                    }
                    if (random >10 && random < 7)
                    {
                        printf ("\nSILNY ATAK WROGA\n");
                        heavyAttackEnemy(enemy,player);
                        if(deathOfPlayer)
                        {
                            break;
                        }
                        printf ("\nHP GRACZA : %d   MP GRACZA: %d\nHP WROGA: %d\n", player -> getHp(),player -> getMp(), enemy -> getHp());
                    }
                enemyTurn = false;
                };
            };
            };
            if(deathOfPlayer)
            {
                playerTurn = false;
                break;
            }
            else
            {
                playerTurn = true;
            }
}
system("PAUSE");
system("cls");
}

bool Fight::getDeathOfPlayer()
{
    return deathOfPlayer;
}

Fight::Fight(Player *player, Enemy *enemy)
{
    this->player = player;
    this->enemy = enemy;
    deathOfPlayer = false;
}
