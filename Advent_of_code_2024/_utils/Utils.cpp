#include "Utils.h"
#include <windows.h>
#include <string>
namespace Utils
{

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void printToCoordinates(int x, int y, const std::string& s)
{
    gotoxy(x, y);
    printf("%s", s.c_str());
    //va_list args;
    //va_start(args, format);
    //printf("\033[%d;%dH", x, y);
    //vprintf(format, args);
    //va_end(args);
    //fflush(stdout);
}
}