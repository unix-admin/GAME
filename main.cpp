#include "win_console.h"
#include "unitDB.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
#include<iomanip>
#include<fstream>


using namespace std;

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
            if((unit.x + 1) < 119)
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
        for(int i = x;i<118;++i)
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
void drawUnit(sUnit &unit)
{
    switch(unit.meType)
    {
        case MEDIC:
        {
            char ch = 1;
            print_char(ch, unit.x, unit.y, Light_Green);
            break;
        }
        case GRENADER:
        {
            char ch = 2;
            print_char(ch, unit.x, unit.y, Light_Green);
            break;
        }
        case SOLDIER:        
        {
            char ch = 3;
            print_char(ch, unit.x, unit.y, Light_Green);
            break;
        }
        break;
    }
}
sUnit  *activateUnit(sUnit *psUnitsArray, sUnit *pUnit, int *size)
{
    int previousUnit;
    previousUnit = pUnit->number;
    if (previousUnit < *size-1)
        pUnit = &psUnitsArray[previousUnit+1];
    else pUnit = &psUnitsArray[0]; ;
    return pUnit;
}

int main()
{
    console_init();
    sUnit *pUnit = 0;
    int size;
    sUnit *psUnitsArray = NULL;
    psUnitsArray = readUnitsData(size);
    for (int i(0);i<size;++i)
    {
        pUnit = &psUnitsArray[i];
        pUnit->number = i;
        drawUnit(*pUnit);
    }
    pUnit = &psUnitsArray[0];
    eCKeyKode key;    
    bool isRun = true;
    for(;isRun;)
    {
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
             //   isRun = false;
             pUnit = activateUnit(psUnitsArray,pUnit, &size);
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
            case KEY_ACTIVATE:
            {
              //  activateUnit(psUnitsArray,pUnit,);
                //fire(pUnit->keyCurrent, pUnit->x, pUnit->y);
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
