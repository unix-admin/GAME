#ifndef _WIN_CONSOLE_H_
#define _WIN_CONSOLE_H_

#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include <ostream>
#include <iostream>

enum eCColor
{
     Black = 0
    ,Blue
    ,Green
    ,Aqua
    ,Red
    ,Purple
    ,Yellow
    ,White
    ,Gray
    ,Light_Blue
    ,Light_Green
    ,Light_Aqua
    ,Light_Red
    ,Light_Purple
    ,Light_Yellow
    ,Bright_White
};

enum eCKeyKode
{
    UNKNOWN = 0
   ,KEY_ENTER
   ,KEY_ESCAPE
   ,KEY_UP
   ,KEY_LEFT
   ,KEY_RIGHT
   ,KEY_DOWN
   ,KEY_FIRE
};


void console_init();

void print_char(char ch, int x, int y, eCColor color = Yellow);
void delete_char(int x, int y);


eCKeyKode wait_console_key_press();

#endif
