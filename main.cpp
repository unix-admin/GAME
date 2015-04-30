#include "win_console.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
#include<iomanip>
#include<fstream>

//if(kbhit())

using namespace std;

const int MAX_UNIT_NAME = 20;
const int medRange   = 6;
const int medHealth  = 100;
const int medPower   = 50;
const int medPoints  = 10;

enum eTypeUnit
{
    MEDIC = 0
   ,COMMANDER
   ,SOLDIER
   ,SCOUT
   ,SNIPER
};

enum eDirection
{
    UP = 0
   ,DOWN
   ,RIGHT
   ,LEFT
   ,FIRE
};

#pragma pack(push, 1)
struct sUnit
{
    int   x;
    int   y;
    int   range;
    int   health;
    int   power;
    int   points;
    eDirection keyPrevious;
    eDirection keyCurrent;
    char  *pName;

    eTypeUnit type;
};

#pragma pack(pop)


sUnit *readUnitData(int &outSize)
{
    sUnit *res = nullptr;
    // open
    int tmpsize = 0;
    ifstream inFile;
    bool isRead =false;
    inFile.open("c:/game/files/units.txt");
    string line;
    int index = 0;
    while(getline(inFile,line))
    {
        if(!isRead)
        {

            tmpsize atoi(line.c_str());

        }
       // line.find()
    }
    //read

    //close
    inFile.close();
    return res;
}

void fire(eDirection key, int x, int y)
{
            int iter = 1;
    char ch = 43;
    switch (key)
    {
       case UP:
       {
         for(int i=y;i>0;--i)
         {
             if (iter!= 1)
             {
             delete_char(x,y);
             }
             y--;
             print_char(ch,x, y);
             iter++;
             Sleep(50);
         }

         break;
       }
       case DOWN:
       {
        for(int i= y;i<49;++i)
        {
            if (iter!= 1)
            {
            delete_char(x,y);
            }
            y += 1;
            print_char(ch,x, y);
            iter++;
            Sleep(50);

        }
        break;
       }
       case LEFT:
       {
        for(int i = x;i>0;--i)
        {
            if (iter!= 1)
            {
            delete_char(x,y);
            }
            x -= 1;
            print_char(ch,x, y);
            iter++;
            Sleep(50);

        }
        break;
        }
       case RIGHT:
       {
        for(int i = x;i<119;++i)
        {
            if (iter!= 1)
            {
            delete_char(x,y);
            }
            x += 1;
            print_char(ch,x, y);
            iter++;
            Sleep(50);

        }
        break;

       }

    }
    delete_char(x,y);
}

void getUnitControls(sUnit &unit, eDirection direction )
{
    unit.keyPrevious = unit.keyCurrent;
    unit.keyCurrent = direction;

}

sUnit *getMedicUnit()
{
    sUnit *tmp = new sUnit;

    tmp->health = medHealth;
    tmp->points = medPoints;
    tmp->range  = medRange;
    tmp->power  = medPower;
    tmp->type   = MEDIC;

    tmp->x = 0;
    tmp->y = 0;
    tmp->pName = new char[MAX_UNIT_NAME + 1];

    return tmp;
}

void moveUnit(sUnit &unit, eDirection direction)
{
    unit.keyCurrent = direction;
    switch(direction)
    {
        case UP:
        {
            if((unit.y - 1) >= 0)
            {

                delete_char(unit.x, unit.y);
                unit.y -= 1;
            }
            else
                Beep(1000, 50);
            break;
        }
        case DOWN:
        {
            if((unit.y + 1) < 50)
            {
                delete_char(unit.x, unit.y);
                unit.y += 1;
            }
            break;
        }
        case LEFT:
        {
            if((unit.x - 1) >= 0)
            {
                delete_char(unit.x, unit.y);
                unit.x -= 1;
            }
            break;
        }
        case RIGHT:
        {
            if((unit.x + 1) < 120)
            {
                delete_char(unit.x, unit.y);
                unit.x += 1;
            }
            break;
        }

        default:

            break;
    }
}

void drawUnit(sUnit &unit)
{
    switch(unit.type)
    {
        case MEDIC:
        {
            char ch = 1;
            print_char(ch, unit.x, unit.y, Light_Green);
            break;
        }
        case COMMANDER:
        case SOLDIER:
        case SCOUT:
        case SNIPER:
            break;
    }
}

int main()
{
    console_init();

    sUnit *pUnit = 0;
    pUnit = getMedicUnit();
    eCKeyKode key;
    void readUnitData();
    bool isRun = true;
    for(;isRun;)
    {
        // system("cls");
        drawUnit(*pUnit);
        key = wait_console_key_press();
        switch(key)
        {
            case KEY_ENTER:
            {
                print_char('N', 0, 0);
                break;
            }
            case KEY_ESCAPE:
            {
                //print_char('E', 0, 0);
                isRun = false;
                break;
            }
            case KEY_UP:
            {
                moveUnit(*pUnit, UP);
                //print_char('U', 0, 0);
                break;
            }
            case KEY_LEFT:
            {
                moveUnit(*pUnit, LEFT);
                //print_char('L', 0, 0);
                break;
            }
            case KEY_RIGHT:
            {
                moveUnit(*pUnit, RIGHT);
                //print_char('R', 0, 0);
                break;
            }
            case KEY_DOWN:
            {
                moveUnit(*pUnit, DOWN);
                //print_char('D', 0, 0);
                break;
            }
            case KEY_FIRE:
            {
               fire(pUnit->keyCurrent, pUnit->x, pUnit->y);
                //print_char('D', 0, 0);
                break;
            }
            case UNKNOWN:
            default:
            {

                break;
            }

        }

    }
    return 0;
}
