//A star implentation whoosh
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 1000
int startpointx;
int startpointy;
int col,row;
struct grid *headgoals=NULL;
struct grid *headopen=NULL;
struct grid *headclose=NULL;\
int i=0;
int count=0;
struct grid{
    int h;
    int g;
    int f;
    int x;
    int y;
    char value;
    struct grid *perv;
    struct grid *next;
}vertex[MAX][MAX];
struct grid *goal;
struct grid *path[MAX][MAX];
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
            if(traverse(&headopen,&vertex[y][x-1]))
            {
                if(vertex[y][x-1].g>h)
                {
                    vertex[y][x-1].perv=A;
                    vertex[y][x-1].g=h;
                    vertex[y][x-1].f=vertex[y][x-1].g+vertex[y][x-1].h;
                }

            }
            else
            {
            vertex[y][x-1].g=h;
            vertex[y][x-1].f=vertex[y][x-1].g+vertex[y][x-1].h;
            vertex[y][x-1].perv=A;
            push(&headopen,&vertex[y][x-1]);

            }
        }
    }
    if(x<col &&  vertex[y][x+1].value!='#')
    {
        if(!traverse(&headclose,&vertex[y][x+1]))
        {
            h=A->g+1;
            if(traverse(&headopen,&vertex[y][x+1]))
            {
                if(vertex[y][x+1].g>h)
                {
                    vertex[y][x+1].perv=A;
                    vertex[y][x+1].g=h;
                    vertex[y][x+1].f=vertex[y][x+1].g+vertex[y][x+1].h;
                }

            }
            else
            {
            vertex[y][x+1].perv=A;
            vertex[y][x+1].g=h;
            vertex[y][x+1].f=vertex[y][x+1].g+vertex[y][x+1].h;
            push(&headopen,&vertex[y][x+1]);
            }
        }
    }
    if(y>0 && vertex[y-1][x].value!='#')
    {
         if(!traverse(&headclose,&vertex[y-1][x]))
        {
            h=A->g+1;

            if(traverse(&headopen,&vertex[y-1][x]))
            {
                if(vertex[y-1][x].g>h)
                {
                    vertex[y-1][x].perv=A;
                    vertex[y-1][x].g=h;
                    vertex[y-1][x].f=vertex[y-1][x].g+vertex[y-1][x].h;
                }

            }
            else
            {
            vertex[y-1][x].perv=A;
            vertex[y-1][x].g=h;
            vertex[y-1][x].f=vertex[y-1][x].g+vertex[y-1][x].h;
            push(&headopen,&vertex[y-1][x]);

            }
        }
    }
    if(y<row && vertex[y+1][x].value!='#')
    {
         if(!traverse(&headclose,&vertex[y+1][x]))
        {
            h=A->g+1;
            if(traverse(&headopen,&vertex[y+1][x]))
            {
                if(vertex[y+1][x].g>h)
                {
                    vertex[y+1][x].perv=A;
                    vertex[y+1][x].g=h;
                    vertex[y+1][x].f=vertex[y+1][x].g+vertex[y+1][x].h;
                }
            }
            else
            {
            vertex[y+1][x].perv=A;
            vertex[y+1][x].g=h;
            vertex[y+1][x].f=vertex[y+1][x].g+vertex[y+1][x].h;
            push(&headopen,&vertex[y+1][x]);
            }
        }
    }
    if(x<col && y>row && vertex[y-1][x+1].value!='#')
    {
         if(!traverse(&headclose,&vertex[y-1][x+1]))
        {
            h=A->g+1;
            if(traverse(&headopen,&vertex[y-1][x+1]))
            {
                if(vertex[y-1][x+1].g>h)
                {
                    vertex[y-1][x+1].perv=A;
                    vertex[y-1][x+1].g=h;
                    vertex[y-1][x+1].f=vertex[y-1][x+1].g+vertex[y-1][x+1].h;
                }
            }
            else
            {
            vertex[y-1][x+1].perv=A;
            vertex[y-1][x+1].g=h;
            vertex[y-1][x+1].f=vertex[y-1][x+1].g+vertex[y-1][x+1].h;
            push(&headopen,&vertex[y-1][x+1]);
            }
        }
    }
    if(x>0 && y>0 && vertex[y-1][x-1].value!='#')
    {
         if(!traverse(&headclose,&vertex[y-1][x-1]))
        {
            h=A->g+1;
            if(traverse(&headopen,&vertex[y-1][x-1]))
            {
                if(vertex[y-1][x-1].g>h)
                {
                  vertex[y-1][x-1].perv=A;
                  vertex[y-1][x-1].g=h;
                  vertex[y-1][x-1].f=vertex[y-1][x-1].g+vertex[y-1][x-1].h;
                }
            }
            else
            {
            vertex[y-1][x-1].perv=A;
            vertex[y-1][x-1].g=h;
            vertex[y-1][x-1].f=vertex[y-1][x-1].g+vertex[y-1][x-1].h;
            push(&headopen,&vertex[y-1][x-1]);
            }
        }
    }
    if(x<col && y<row && vertex[y+1][x+1].value!='#')
    {
         if(!traverse(&headclose,&vertex[y+1][x+1]))
        {
            h=A->g+1;

            if(traverse(&headopen,&vertex[y+1][x+1]))
            {
                if(vertex[y+1][x+1].g>h)
                {
                    vertex[y+1][x+1].perv=A;
                    vertex[y+1][x+1].g=h;
                    vertex[y+1][x+1].f=vertex[y+1][x+1].g+vertex[y+1][x+1].h;
                }

            }
            else  vertex[y+1][x-1].perv=A;
            {
            vertex[y+1][x+1].perv=A;
            vertex[y+1][x+1].g=h;
            vertex[y+1][x+1].f=vertex[y+1][x+1].g+vertex[y+1][x+1].h;
            push(&headopen,&vertex[y+1][x+1]);
            }
        }
    }
    if(x>0 && y<row && vertex[y+1][x-1].value!='#')
    {
          if(!traverse(&headclose,&vertex[y+1][x-1]))
        {

            h=A->g+1;
            if(traverse(&headopen,&vertex[y+1][x-1]))
            {
                if(vertex[y+1][x-1].g>h)
                {
                    vertex[y+1][x-1].perv=A;
                    vertex[y+1][x-1].g=h;
                    vertex[y+1][x-1].f=vertex[y+1][x-1].g+vertex[y+1][x-1].h;
                }

            }
            else
            {
            vertex[y+1][x-1].perv=A;
            vertex[y+1][x-1].g=h;
            vertex[y+1][x-1].f=vertex[y+1][x-1].g+vertex[y+1][x-1].h;
            push(&headopen,&vertex[y+1][x-1]);
            }
        }
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
                vertex[j][i].perv=NULL;
                if(ch=='*')
                {
                    push(&headgoals,&vertex[j][i]);
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
void trackpath(struct grid* A)
{
    int j=0;
    struct grid* temp=A;
    while(temp!=NULL)
    {
        path[i][j]=temp;
        temp=temp->perv;
        j++;
    }
    i++;

}
void search()
{
    int j=0;
    push(&headopen,&vertex[startpointy][startpointx]);
    struct grid* cur=&vertex[startpointy][startpointx];
    struct grid* temp=headopen;
    while(headopen!=NULL)
    {
          if(cur==goal)
          {
              trackpath(cur);
              headopen->next=NULL;
              headclose->next=NULL;
              headopen=NULL;
              headclose=NULL;
              cur->value='1';
              cur->perv=NULL;
              startpointx=cur->x;
              startpointy=cur->y;
              return;
          }
          else
          {
              pop(&headopen,cur);
              push(&headclose,cur);
              addneighbours(cur);
              temp=headopen;
              while(temp!=NULL)
              {
                  if(temp->f<=cur->f)
                    cur=temp;
                temp=temp->next;
              }
              temp=headopen;
            }
    }
}
int distance(int x1,int x2,int y1,int y2)
{
    int y=abs(y1-y2);
    int x=abs(x1-x2);
    int z=(x*x)+(y*y);
    return z;
}
 void setvalue()
{
    int i,j,z,x,y;
    for(i=0;i<=row;i++)
    {
        for(j=0;j<=col;j++)
        {
            z=distance(goal->x,j,goal->y,i);
            vertex[i][j].h=z;
            vertex[i][j].f= vertex[i][j].h+vertex[i][j].g;
        }
    }
}
void findthenearestfood()
{
     int x,y;
     struct grid* temp=headgoals;
     y=distance(headgoals->x,startpointx,headgoals->y,startpointy);
     goal=headgoals;
     while(temp!=NULL)
     {

         x=distance(temp->x,startpointx,temp->y,startpointy);
          if(x<y && temp->value=='*')
          {
             goal=temp;
             y=x;
          }
           temp=temp->next;
     }
}
int main()
{
    int k,l;
    read();
    while(count){
        findthenearestfood();
        setvalue();
        search();
        count--;
    }

  for(k=0;k<i;k++)
  {
      for(l=0;path[k][l]!=NULL;l++)
        printf("%d %d\n",path[k][l]->y,path[k][l]->x);
  }//this is the path without graphics;

 }



