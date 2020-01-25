//My A star implentation modified for multiple goals
//Please note what you re about to see is a work of fiction and has no scientific value
//my code cant find the shortest shortest path but can find the shortest path between 2 node and several goals if lucky it all depends on the situation
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 1000//we can change MAX anytime to increase our map size
int startpointx;//the start where Pacman is
int startpointy;
int col,row;// our map size i have used many global variables :) as
struct grid *headopen=NULL;//to initiate my openlist
struct grid *headclose=NULL;//to nitiate my closelist both are FIFO
int i=0;
int count=0;// to count the number of goals(foods or whatever)
int numberofpath[MAX];
struct grid{
    int h;//hurestic
    int g;//cost to get there
    int f;// sum of h and g
    int x;
    int y;
    char value;
    struct grid *perv;//
    struct grid *next;//for tracking the path later
}vertex[MAX][MAX];//every point in the screen is a node
struct grid *goal; //the goal i pass to A star to search for
struct grid *goals[MAX];//i choose the nearest goal form goals here
struct grid *path[MAX][MAX];//for saving the path
void push(struct grid** head,struct grid* A)//to push into a list
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
void pop(struct grid**head,struct grid* A)//to pop
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
int traverse(struct grid**head,struct grid* A)//to move through a list
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


void addneighbours(struct grid *A)//adding all the available and adjacent nodes of current
{
    int h;
    int x=A->x;
    int y=A->y;
    struct grid *temp=headopen;
    if(x>0  && vertex[y][x-1].value!='#')//adding all the 8 neighbous of current becuz it can move diagnally
    {
        if(!traverse(&headclose,&vertex[y][x-1]))
        {
            h=A->g+1;
            if(traverse(&headopen,&vertex[y][x-1]))//if i had already checked the node before i only update it if it is more efficient
            {
                if(vertex[y][x-1].g>h)
                {
                    vertex[y][x-1].perv=A;
                    vertex[y][x-1].g=h;
                    vertex[y][x-1].f=vertex[y][x-1].g+vertex[y][x-1].h;
                }

            }
            else//if i hadnt i just push it into open list
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
void gotoxy(int x, int y)//a fucntion to move the cursor through console
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void read()//my code gets the map form a file and has no alternative unfortunately
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
                    goals[count]=&vertex[j][i];
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
void trackpath(struct grid* A)//to track the goal backwards to the starting node
{
    int j=0;
    int w=0;
    struct grid* temp=A;
    while(temp!=NULL)
    {
        path[i][j]=temp;
        temp=temp->perv;
        j++;
    }
    i++;

}
void search()//this fucntion carries the heavy burden of searcing for the goal with the help of other functions
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
int distance(int x1,int x2,int y1,int y2)//calculates euclidean distance between two points
{
    int y=abs(y1-y2);
    int x=abs(x1-x2);
    int z=(x*x)+(y*y);
    return z;
}
 void setvalue()//sets the heuristic
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
void findthenearestfood()//this was my innovation dont know how much accurate it is as a heuristic
{
int x,y;
x=1000000;
for(int i=0;i<count;i++)
{
    if(goals[i]->value=='*')
    {
        y=distance(goals[i]->x,startpointx,goals[i]->y,startpointy);
        if(y<x)
        {
             goal=goals[i];
             x=y;
        }


    }
}
}
void drawmap()//draws the map
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
void animate()//animates the movement of pacman
{
    int i,j;
    for(i=0;i<count;i++)
     {
         for(j=numberofpath[i]-1;j>=0;j--)
         {
             gotoxy(path[i][j]->x,path[i][j]->y);
             printf(".");
             if(path[i][j-1]!=NULL)
             {
                  gotoxy(path[i][j-1]->x,path[i][j-1]->y);
                  printf("o");
                  Beep(1233,700);
             }
         }
     }

}
int main()
{
    int i,j;
    int h=0;
    read();
    drawmap();
    int k=count;
    while(k)//calling the A star count times(number of goals)
        {
        findthenearestfood();
        setvalue();
        search();
        k--;
        }
    for(i=0;i<count;i++)//
    {
        for(j=0;path[i][j];j++)
        {
        }
          numberofpath[i]=j;
    }
 animate();
 Sleep(500);
 system("CLS");
 printf("Pacman has finished eating thx for watching...\n");
}

