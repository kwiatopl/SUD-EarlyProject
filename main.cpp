#include "creature.h"
#include "location.h"
#include "gui.h"
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
srand(time(NULL));

Player *gracz= new Player(); // Tworzenie gracza

Location *lokacja1 = new Location(7,7,gracz); // Tworzenie lokacji

gracz->setActualLocation(lokacja1); // Ustawienie aktualnej lokacji dla gracza

GUI *gui = new GUI(gracz, lokacja1);  // Tworzenie interfejsu dla gracza i danej lokacji


cout << "#######################" << endl;
cout << "#                     #" << endl;
cout << "# SINGLE USER DUNGEON #" << endl;
cout << "#   Adam Kwiatkowski  #" << endl;
cout << "#                     #" << endl;
cout << "#######################" << endl;

printf ("\n\nNACISNIJ SPACJE, ABY ROZPOCZAC PRZYGODE!\n\n");

int x = getch();

while (x != 32)
{
    x = getch();
}

gui->render();  // Wywolanie metody render, wyswietlajacej aktualna pozycje gracza

delete gracz;
delete lokacja1;        // Zwalnianie pamieci
delete gui;

return 0;
}
