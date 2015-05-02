#ifndef UNITDB_H
#define UNITDB_H

#ifndef NULL
#define NULL 0
#endif

const char COMMENT_CHAR = ';';

enum eDirection
{
    UP = 0
   ,DOWN
   ,RIGHT
   ,LEFT
   ,FIRE
};

enum eUnitType
{
   MEDIC = 0
  ,GRENADER
  ,SOLDIER
  ,UNKNOWNUNIT
};

struct sUnit
{
    int miInithealth;
    int miMaxhealth;
    int miPoints;
    int miRange;
    int miPower;
    int miHealingrange;
    int x;
    int y;
    int number;
    eDirection keyPrevious;
    eDirection keyCurrent;

    eUnitType meType;
};

/*
 *
*/
sUnit *readUnitsData(int &outSize);


#endif // UNITDB_H
