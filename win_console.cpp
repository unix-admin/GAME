#include "win_console.h"


using namespace std;

//system("COLOR FC");

HANDLE gConsoleHandle = 0;

void console_init()
{
    CONSOLE_CURSOR_INFO cursor_info;
    gConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    system("mode con cols=120 lines=50");
    cursor_info.dwSize   = 20;
    cursor_info.bVisible = 0;
    SetConsoleCursorInfo(gConsoleHandle, &cursor_info);
}

void print_char(char ch, int x, int y, eCColor color)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(gConsoleHandle, pos);
    SetConsoleTextAttribute(gConsoleHandle, color);
    cout << ch;
}

void delete_char(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(gConsoleHandle, pos);
    cout << " ";
}

eCKeyKode wait_console_key_press()
{
    int key = 0;
    key = getch();

    if(key == 0x00 || key == 0xE0)// extended key
    {
        switch(getch())
        {
            case 72:
                return KEY_UP;
            case 75:
                return KEY_LEFT;
            case 77:
                return KEY_RIGHT;
            case 80:
                return KEY_DOWN;
            default:
                return UNKNOWN;
        }
    }

    switch(key)
    {
        case 13:
            return KEY_ENTER;
        case 27:
            return KEY_ESCAPE;
        case 32:
            return KEY_FIRE;
        case 60:
            return KEY_ACTIVATE;

        default:
            return UNKNOWN;
    }

    return UNKNOWN;
}
















