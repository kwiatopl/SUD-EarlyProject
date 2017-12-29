#include "event.h"

Event::Event(Player *player)
{
    triggered = false;
    this -> player = player;
}

void Event::adjust()
{
    hp = player -> getHp() - 15;
    attack = player -> getAttack() - 2;
    defence = player -> getDefence() - 2;
    level = player -> getLvl() - 1;
}

std::string Event::randName()
{
    std::string arrayOfNames[9]={"Calkopotwor","Rozniczkownica","Logarytmozaur","Pani Jadzia z dziekanatu","Ekstreminium","C++","Laboratomaur","Zly pan z ochrony","Super zly pan z ochrony"};
    int random = (rand()%9)+0;
    return name = arrayOfNames[random];
}

void Event::launch()
{
    if (!triggered)
    {
        int random = (std::rand()%100)+0;
        if (random <= 15)
            {
                printf("\nZNALAZLES POTION!\n");
                int random2 = (std::rand()%2)+1;
                switch (random2)
                {
                case 1:
                    {
                        printf ("\nMANA POTION!\n");
                        if (player -> mpCount <= 3)
                        {
                            player -> mpCount++;
                        }
                        else
                        {
                            printf("\nBRAK MIEJSCA W EKWIPUNKU!\n");
                        }
                        break;
                    }
                case 2:
                    {
                        printf ("\nHP POTION\n");
                        if (player -> hpCount <= 3)
                        {
                            player -> hpCount++;
                        }
                        else
                        {
                            printf("\nBRAK MIEJSCA W EKWIPUNKU!\n");
                        }
                        break;
                    }
                }
                system("PAUSE");
            };
        if (random < 100 && random >= 75)
            {
                printf("\nWalka!\n");
                adjust();
                Enemy *enemy = new Enemy(randName(),hp,attack,defence,level);
                Fight *fight = new Fight(player, enemy);
                fight -> turnBasedSystem();
                system("PAUSE");
                delete enemy;
                delete fight;
            };
        triggered = true;
    };
}


