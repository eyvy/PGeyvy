#include <stdio.h>
#include <windows.h>
#define MAX 1000
struct grid{
    int x;
    int y;
    char value;
}vertex[MAX][MAX];
struct grid* goals[MAX];
int x=0;
int y=0;
int col,row;
int count;
void read()
{

 FILE *fp;
 fp=fopen("map.txt","r");
 char ch;
 int i=0,j=0,k=0,flag=0;
 while((ch=fgetc(fp))!=EOF)
 {
     if(ch=='\n')
     {
         col=i-1;
         flag=1;

     }
     else
     {
       if(flag)
        {
            j++;
            i=0;
        }

        if(ch!='{' && ch!='}' && ch!=',' && ch!='’' && ch!='‘' && ch!=' ')
            {
                if(ch=='0')
                {
                    x=i;
                    y=j;
                }
                vertex[j][i].value=ch;
                vertex[j][i].x=i;
                vertex[j][i].y=j;
                if(ch=='*')
                {
                    count++;
                }

                i++;
            }
        flag=0;
    }
 }
 row=j;
 fclose(fp);
}
int check()
{
 int i,j;
 for(i=0;i<=row;i++)
 {
     for(j=0;j<=col;j++)
     {
         if(vertex[i][j].value=='*')

                return 0;
     }
 }
 return 1;
}
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void printfvertex()
{
    int i,j;
    for(i=0;i<=row;i++)
    {
        for(j=0;j<=col;j++)
        {
            if(vertex[i][j].value=='*')
            {
                printf("%c",3);
            }
             if(vertex[i][j].value=='1')
            {
                printf(".");
            }
             if(vertex[i][j].value=='#')
            {
                printf("%c",223);
            }
             if(vertex[i][j].value=='0')
            {
                printf("o");
            }
        }
        printf("\n");
    }
}

void right()
{
    if(x<col && vertex[y][x+1].value!='#')
    {
        gotoxy(x,y);
        printf(".");
        x++;
        gotoxy(x,y);
        Beep(600,600);
        printf("o");
        if(vertex[y][x+1].value=='*')
        {

            vertex[y][x+1].value='1';
        }
    }
}
void left()
{
     if(x>0 &&vertex[y][x-1].value!='#')
    {
        gotoxy(x,y);
        printf(".");
        x--;
        gotoxy(x,y);
        Beep(600,600);
        printf("o");
        if(vertex[y][x-1].value=='*')
        {

            vertex[y][x-1].value='1';
        }
    }
}

void up()
{
     if(y>0 &&vertex[y-1][x].value!='#')
    {
        gotoxy(x,y);
        printf(".");
        y--;
        gotoxy(x,y);
        Beep(600,600);
        printf("o");
        if(vertex[y-1][x].value=='*')
        {

            vertex[y-1][x].value='1';
        }
    }
}

void down()
{
     if(y<row &&vertex[y+1][x].value!='#')
    {
        gotoxy(x,y);
        printf(".");
        y++;
        gotoxy(x,y);
        printf("o");
        Beep(600,600);
        if(vertex[y+1][x].value=='*')
        {

            vertex[y+1][x].value='1';
        }
    }
}
void move()
{
 int chr1,chr2;
while(1)
{

   chr1 = _getch();
 if (chr1 == 0xE0)
 {
  chr2 = _getch();
  switch(chr2)
  {
   case 72:  up();
      break;
   case 80:  down();
      break;
   case 75:  left();
      break;
   case 77:  right();
      break;
  };
 }
 return 0;
}
}

int main()
{
read();
printfvertex();
gotoxy(x,y);
while(12)
{
    move();
    if(check())
    {
         break;

    }

}
 Sleep(500);
 system("CLS");
 printf("You beat the game thx for playing...");
 getchar();
 }
