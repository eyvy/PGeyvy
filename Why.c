#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y) //whooosh first function
{
    COORD coordinate;//allegedly  a structure of some sort
    coordinate.X = x;//column
    coordinate.Y = y;//row
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);//handle?:/
}
int main()
{

   printf("yay");
     gotoxy(7,7);
   printf("yay");
   gotoxy(5,4);
   printf("dfs");

}

