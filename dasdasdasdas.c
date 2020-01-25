#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#define MAX 100
int startpointx;
int startpointy;
int col,row;
int size;
struct grid{
    int x;
    int g;
    int f;
    int h;
    int y;
    char value;
    struct grid *perv;
    struct grid *next;
}vertex[MAX][MAX];
struct grid *headopen=NULL;
struct grid *headclose=NULL;
struct grid *goals[MAX];
int traverse(struct grid**head,struct grid* A)
{
struct grid* temp=*head;
if(temp==NULL)
    return 0;

while(temp!=NULL)
{
    if(temp==A)
        return 1;
    temp=temp->next;
}
return 0;
}
void push(struct grid** head,struct grid* A)
{

   if(*head==NULL)
    {
       A->next=NULL;
       *head=A;
    }
    else
    {
       A->next=*head;
       *head=A;
    }
}
void pop(struct grid**head,struct grid* A)
{
    struct grid* temp=*head;
if(*head==A)
 {
  *head=A->next;

 }
 else
 {
 while(temp->next!=NULL)
 {
     if(temp->next==A)
     {
         temp->next=A->next;
     }
     else
         temp=temp->next;
 }
 }
}
void addneighbours(struct grid *A)
{
    int h;
    int x=A->x;
    int y=A->y;
    struct grid *temp=headopen;
    if(x>0  && vertex[y][x-1].value!='#')
    {
        if(!traverse(&headclose,&vertex[y][x-1]))
        {

            h=A->g+1;
            vertex[y][x-1].perv=A;
            if(traverse(&headopen,&vertex[y][x-1]))
            {
                if(vertex[y][x-1].g>h)
                {

                    vertex[y][x-1].g=h;
                    vertex[y][x-1].f=vertex[y][x-1].g+vertex[y][x-1].h;
                }

            }
            else
            {
            vertex[y][x-1].g=h;
            vertex[y][x-1].f=vertex[y][x-1].g+vertex[y][x-1].h;
            push(&headopen,&vertex[y][x-1]);

            }
        }
        else
        printf("rejected: %d %d %d\n",vertex[y][x-1].y,vertex[y][x-1].x,vertex[y][x-1].f);
    }
    if(x<col &&  vertex[y][x+1].value!='#')
    {
        if(!traverse(&headclose,&vertex[y][x+1]))
        {
            h=A->g+1;
            vertex[y][x+1].perv=A;
            if(traverse(&headopen,&vertex[y][x+1]))
            {
                if(vertex[y][x+1].g>h)
                {
                    vertex[y][x+1].g=h;
                    vertex[y][x+1].f=vertex[y][x+1].g+vertex[y][x+1].h;
                }

            }
            else
            {
            vertex[y][x+1].g=h;
            vertex[y][x+1].f=vertex[y][x+1].g+vertex[y][x+1].h;
            push(&headopen,&vertex[y][x+1]);
            }
        }
        else
        printf("rejected: %d %d %d\n",vertex[y][x+1].y,vertex[y][x+1].x,vertex[y][x+1].f);
    }
    if(y>0 && vertex[y-1][x].value!='#')
    {
         if(!traverse(&headclose,&vertex[y-1][x]))
        {
            h=A->g+1;
            vertex[y-1][x].perv=A;
            if(traverse(&headopen,&vertex[y-1][x]))
            {
                if(vertex[y-1][x].g>h)
                {
                    vertex[y-1][x].g=h;
                    vertex[y-1][x].f=vertex[y-1][x].g+vertex[y-1][x].h;
                }

            }
            else
            {
            vertex[y-1][x].g=h;
            vertex[y-1][x].f=vertex[y-1][x].g+vertex[y-1][x].h;
            push(&headopen,&vertex[y-1][x]);

            }
        }
        else
        printf("rejected: %d %d %d\n",vertex[y-1][x].y,vertex[y-1][x].x,vertex[y-1][x].f);
    }
    if(y<row && vertex[y+1][x].value!='#')
    {
         if(!traverse(&headclose,&vertex[y+1][x]))
        {
            h=A->g+1;
            vertex[y+1][x].perv=A;
            if(traverse(&headopen,&vertex[y+1][x]))
            {
                if(vertex[y+1][x].g>h)
                {
                    vertex[y+1][x].g=h;
                    vertex[y+1][x].f=vertex[y+1][x].g+vertex[y+1][x].h;
                }
            }
            else
            {
            vertex[y+1][x].g=h;
            vertex[y+1][x].f=vertex[y+1][x].g+vertex[y+1][x].h;
            push(&headopen,&vertex[y+1][x]);
            }
        }
        else
        printf("rejected: %d %d %d\n",vertex[y+1][x].y,vertex[y+1][x].x,vertex[y+1][x].f);
    }
    if(x<col && y>row && vertex[y-1][x+1].value!='#')
    {
         if(!traverse(&headclose,&vertex[y-1][x+1]))
        {
            h=A->g+1;
            vertex[y-1][x+1].perv=A;
            if(traverse(&headopen,&vertex[y-1][x+1]))
            {
                if(vertex[y-1][x+1].g>h)
                {
                    vertex[y-1][x+1].g=h;
                    vertex[y-1][x+1].f=vertex[y-1][x+1].g+vertex[y-1][x+1].h;
                }
            }
            else
            {
            vertex[y-1][x+1].g=h;
            vertex[y-1][x+1].f=vertex[y-1][x+1].g+vertex[y-1][x+1].h;
            push(&headopen,&vertex[y-1][x+1]);
            }
        }
        else
        printf("rejected: %d %d %d\n",vertex[y-1][x+1].y,vertex[y-1][x+1].x,vertex[y-1][x+1].f);
    }
    if(x>0 && y>0 && vertex[y-1][x-1].value!='#')
    {
         if(!traverse(&headclose,&vertex[y-1][x-1]))
        {
            h=A->g+1;
            vertex[y-1][x-1].perv=A;
            if(traverse(&headopen,&vertex[y-1][x-1]))
            {
                if(vertex[y-1][x-1].g>h)
                {
                  vertex[y-1][x-1].g=h;
                  vertex[y-1][x-1].f=vertex[y-1][x-1].g+vertex[y-1][x-1].h;
                }
            }
            else
            {
            vertex[y-1][x-1].g=h;
            vertex[y-1][x-1].f=vertex[y-1][x-1].g+vertex[y-1][x-1].h;
            push(&headopen,&vertex[y-1][x-1]);
            }
        }
        else
         printf("rejected: %d %d %d\n",vertex[y-1][x-1].y,vertex[y-1][x-1].x,vertex[y-1][x-1].f);
    }
    if(x<col && y<row && vertex[y+1][x+1].value!='#')
    {
         if(!traverse(&headclose,&vertex[y+1][x+1]))
        {
            h=A->g+1;
            vertex[y+1][x+1].perv=A;
            if(traverse(&headopen,&vertex[y+1][x+1]))
            {
                if(vertex[y+1][x+1].g>h)
                {
                    vertex[y+1][x+1].g=h;
                    vertex[y+1][x+1].f=vertex[y+1][x+1].g+vertex[y+1][x+1].h;
                }

            }
            else
            {
            vertex[y+1][x+1].g=h;
            vertex[y+1][x+1].f=vertex[y+1][x+1].g+vertex[y+1][x+1].h;
            push(&headopen,&vertex[y+1][x+1]);
            }
        }
        else
            printf("rejected: %d %d %d\n",vertex[y+1][x+1].y,vertex[y+1][x+1].x,vertex[y+1][x+1].f);
    }
    if(x>0 && y<row && vertex[y+1][x-1].value!='#')
    {
          if(!traverse(&headclose,&vertex[y+1][x-1]))
        {

            h=A->g+1;
            vertex[y+1][x-1].perv=A;
            if(traverse(&headopen,&vertex[y+1][x-1]))
            {
                if(vertex[y+1][x-1].g>h)
                {
                    vertex[y+1][x-1].g=h;
                    vertex[y+1][x-1].f=vertex[y+1][x-1].g+vertex[y+1][x-1].h;
                }

            }
            else
            {
            vertex[y+1][x-1].g=h;
            vertex[y+1][x-1].f=vertex[y+1][x-1].g+vertex[y+1][x-1].h;
            push(&headopen,&vertex[y+1][x-1]);
            }
        }
        else
            printf("rejected: %d %d %d\n",vertex[y+1][x-1].y,vertex[y+1][x-1].x,vertex[y+1][x-1].f);
    }
}
void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void read()
{

 FILE *fp;
 fp=fopen("why.txt","r");
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
                    startpointx=i;
                    startpointy=j;
                }
                vertex[j][i].value=ch;
                vertex[j][i].x=i;
                vertex[j][i].y=j;
                if(ch=='*')
                {
                    goals[k]=&vertex[j][i];
                    k++;
                    size=k;
                }

                i++;
            }
        flag=0;
    }
 }
 row=j;
 fclose(fp);
}
int main()
{
  read();
  printf("%d",vertex[2][1].g);
}
