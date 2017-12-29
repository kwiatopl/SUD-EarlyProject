#include "player.h"

Player::Player()
{
    this->maxHp = 100;
    this->maxMp = 100;
    this->setAttack(10);
    this->setDefence(10);
    this->setLvl(10);
    this->setHp(100);
    this->setMp(100);
    this->setExp(0);
    this->coordinateX=0;
    this->coordinateY=0;
    mpCount = 0;
    hpCount = 0;
    multiplier = 1;
}

void Player::useHpPotion()
{
    if(hpCount > 0 && hpCount <=3)
    {
        HpPotion *hppotion = new HpPotion(this);
        hppotion -> effect();
        if(getHp() > maxHp)
        {
            setHp(maxHp);
        }
        printf ("\nUZYLES HP POTION, TWOJE ZYCIE TO: %d", this -> getHp());
        hpCount--;
        delete hppotion;
    }
    else
    {
        printf ("\nNIE POSIADASZ POTIONOW!\n");
    }
}

void Player::useMpPotion()
{
    if(mpCount > 0 && mpCount <=3)
    {
        MpPotion *mppotion = new MpPotion(this);
        mppotion -> effect();
        if(getMp() > maxMp)
        {
            setMp(maxMp);
        }
        printf("\nUZYLES MP POTION, TWOJA MANA TO: %d", this -> getMp());
        mpCount--;
        delete mppotion;
    }
    else
    {
        printf ("\nNIE POSIADASZ POTIONOW!\n");
    }
}

void Player::levelUp()
{
    if(this -> getExp() >= multiplier*200)
    {
    printf("\nNOWY POZIOM!\n");
    this -> setLvl (this -> getLvl() + 1);
    printf("\nPOZIOM: %d",this -> getLvl());
    this -> setAttack (this -> getAttack() + 10);
    printf("\nATAK: %d", this -> getAttack());
    this -> setDefence (this -> getDefence() + 10);
    printf("\nOBRONA: %d", this -> getDefence());
    this -> setHp (100 + multiplier*10);
    this -> setMaxHp (100 + multiplier*10);
    printf("\nHP: %d", this -> getHp());
    this -> setMp (100 + multiplier*10);
    this -> setMaxMp (100 + multiplier*10);
    printf("\nMP: %d", this -> getMp());
    multiplier ++;
    }
}

void Player::moveUp()
{
    if(this->actualLocation->getY() > this->coordinateY)
    {
        coordinateY++;
    }
}

void Player::moveDown()
{
    if(this->coordinateY > 0)
    {
        coordinateY--;
    }
}
void Player::moveLeft()
{
    if(this->coordinateX > 0)
    {
        coordinateX--;
    }
}
void Player::moveRight()
{
    if(this->actualLocation->getX() > this->coordinateX)
    {
        coordinateX++;
    }
}

void Player::setCoordinates(int x, int y)
{
    this -> coordinateX = x;
    this -> coordinateY = y;
}

void Player::setExp(int val)
{
    this -> exp = val;
}

void Player::setMaxHp(int val)
{
    this -> maxHp = val;
}

void Player::setMaxMp(int val)
{
    this -> maxMp = val;
}

void Player::setMp(int val)
{
    this -> mp = val;
}

void Player::setActualLocation(Location *actualLocation)
{

    this -> actualLocation = actualLocation;

}

void Player::movePlayer(int x)
{
    switch (x)
    {
    case 72:
        moveUp();
        break;
    case 80:
        moveDown();
        break;
    case 77:
        moveRight();
        break;
    case 75:
        moveLeft();
        break;
    }

    Field ***area = this -> actualLocation -> getArea();
    Event* event = area[coordinateX][coordinateY] -> getEvent();
    event -> launch();
    system("cls");
}


int Player::getCoordinateX()
{
    return coordinateX;
}

int Player::getCoordinateY()
{
    return coordinateY;
}

int Player::getExp()
{
    return exp;
}

int Player::getMaxHp()
{
    return maxHp;
}

int Player::getMaxMp()
{
    return maxMp;
}

int Player::getMp()
{
    return mp;
}

