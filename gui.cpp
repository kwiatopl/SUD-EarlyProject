#include "gui.h"


void GUI::render()
{
if(player -> getHp() == 0 )
{
    printf("\n\nGAME OVER!\n\n");
    flag = false;
}
else
{
    player -> levelUp();
    printf("%d, %d\n", player -> getCoordinateX(), player -> getCoordinateY());
    drawMap();
    keyPressed();
    if (flag == true)
    {
        this->render();
    };
}
}

void GUI::keyPressed()      //KLAWISZE
{
    unsigned int x = getch();       //SPRAWDZAMY CO WCISNIETO

    if(x == 0 || x==224)
    {
        player -> movePlayer(getch());
    }
        //warunek na wystepowanie przejscia do nastepnej lokacji
    if(x == 27)
    {
        flag = false;
        printf("KONIEC");
    }
    if(x == 104)
    {
        player -> useHpPotion();
    }
    if(x == 109)
    {
        player -> useMpPotion();
    }

}

void GUI::drawMap()
{

for (int row = locationY; row >= 0; --row)
	{
        for (int col = 0; col < locationX+1; ++col)
        {
            if (row % 2 == 0)
            {
                if (row == player -> getCoordinateY() && col == player -> getCoordinateX())
                {
                    cout << "* ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            else
            {
                if (row == player -> getCoordinateY() && col == player -> getCoordinateX())
                {
                    cout << "* ";
                }
                else
                {
                cout << "_ ";
                }
            }
        }
    cout << endl;
    }

}


GUI::GUI(Player *player, Location *location)
{
    flag = true;
    this -> player = player;
    this -> location = location;
    locationX = location -> getX();
    locationY = location -> getY();
};

