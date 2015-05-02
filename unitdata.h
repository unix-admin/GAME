//#pragma once;
#ifndef UNITDATA
#define UNITDATA
#include <iostream>



enum eTypeUnit
{
    MEDIC = 0
   ,COMMANDER
   ,SOLDIER
   ,SCOUT
   ,SNIPER
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
    bool   isActiveNow;

    eTypeUnit type;
};
#pragma pack(pop)

void fire(eDirection key, int x, int y);
void moveUnit(sUnit &unit, eDirection direction);

#endif // UNITDATA
