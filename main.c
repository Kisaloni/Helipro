#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
/*
*Global variables
*/
int Block_x[3]={78,39,0};
int Block_y[3]={2,19,15};
int l[3]={9,5,9},lc=0;
int Score=0;
int gameover=1;
int level=59999999;
int Heli_x=99,Heli_y=5;
/*
*Functions
*/
void gotoxy(int,int);
void Setup();/*1*/
void Print_heli();/*2*/
void Welcome();/*3*/
void Menu();/*4*/
void Border();/*5*/
void Draw();/*6*/
void Draw_Heli();/*7*/
void In();/*8*/
void Logic();/*9*/
void Delay();/*10*/
void Draw_Block(int,int,int);/*11*/
void Selectxy(int);/*12*/
void Pause();/*13*/
void Move(char);/*14*/
void Game_over();/*15*/
void Show_Score();/*16*/
/*
* Main Fnction
*/
int main()
{
    Print_heli();
    Welcome();
    while(1)
    {
        Setup();
        while(!gameover)
        {
            Draw();
            In();
            Logic();
        }
        Show_Score();
    }
    return 0;
}
/*
* Definition of Functions
*/
void Setup()
{
    Menu();
    gameover=0;
    Score=0;
    Heli_x=99;
    Heli_y=5;
    Block_x[0]=78;Block_x[1]=39;Block_x[2]=0;
    Block_y[0]=2;Block_y[1]=19;Block_y[2]=15;
    l[0]=9;l[1]=5;l[2]=9;
    lc=0;
}
void Print_heli()
{
    int i,j;
    printf("\a");
/* This is to print the main propeller  */
    gotoxy(4,2);
    for(i=1;i<=40;i++)
    {
        if(i==19||i==20)
        {
            printf("@");
        }
        else
        {
            printf("==");
        }
    }
/* This is to print the main propeller holder (head of helicopter)*/
    gotoxy(40,3);
    printf("||");
    gotoxy(36,4);
    printf("##########");
    gotoxy(32,5);
    printf("##################");
    gotoxy(28,6);
    printf("##########################");
/* This is to print the body of helicopter*/
    gotoxy(10,7);
    int y=8;
    for(i=1;i<=8;i++)
    { static int a=10,b=54;
        for(j=1;j<=60;j++)
        {
            if(j>a&&j<b)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        if(i<5)
        {
            a--;b++;
        }
        else
        {
            a++;b--;
        }
        gotoxy(10,y);
        y++;
    }
/* This is to print the stand of helicopter*/
    int k=20;
    int x=30;
    y=15;
    gotoxy(x,y);
    for(i=1;i<=5;i++)
    {
        printf("|||");
        for(j=1;j<k;j++)
        {
            printf(" ");
        }
        printf("|||");k+=2;x--;y++;
        gotoxy(x,y);
    }
/* This is to print the tail of helicopter*/
    x=100,y=6;
    gotoxy(x,y);
    {
        for(i=7;i<14;i++)
        {
            for(j=1;j<5;j++)
            {
                printf("#");
            }
            if(i<11)
            {
                x--;y=i;
            }
            else
            {
                x++;y=i;
            }
            gotoxy(x,y);
        }
    }
    x=65;y=9;
    gotoxy(x,y);
    for(i=1;i<3;i++)
    {
        for(j=1;j<=32;j++)
        {
            printf("#");
        }
        y++;
        gotoxy(x,y);
    }
/* This is to print the windows of helicopter*/
x=22;y=8;
 k=17;
gotoxy(x,y);
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=k;j++)
        {
            printf(" ");
        }
        if(i<4)
        {
            x--;y++;k++;
        }
        else
        {
            x++;y++;k--;
        }

        gotoxy(x,y);
    }
k=12;
    for(i=1;i<=7;i++)
    {
        static int p=7;
        for(j=1;j<=k;j++)
        {
            printf(" ");
        }
        p++;
        if(i<4)
        {
            k++;
        }
        else
        {
            k--;
        }
        gotoxy(42,p);
    }
    gotoxy(21,14);
    printf("#############");
/*This is to shift the pattern at R.H.S*/

    printf("\n");
}

void Welcome()
{
    gotoxy(0,25);
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(i==2&&j==42)
            {
                printf(" \a\"WELCOME TO HELIPRO\" \a");
                j=63;
            }
            else
            {
                printf("=");
            }
        }
        printf("\n");
    }
    gotoxy(0,28);
    printf("\nPress any key to continue.....");
    getch();
}

void gotoxy(int x,int y)
{
    COORD c;
    fflush(stdout);
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void Menu()
{
    int w1=1;
    int ch_w=1;
    do
    {
        int x=49,y=10;
        system("cls");
        Border();
        for(int i=0;i<5;i++)
        {
            gotoxy(x,y+i);
            for(int j=0;j<20;j++)
            {
                printf("*");

            }
        }
        gotoxy(x+1,y+1);
        printf("\a1.Play            ");
        gotoxy(x+1,y+3);
        printf("2.Exit            ");
        gotoxy(1,30);
        int ch_m=0;
        fflush(stdin);
        scanf("%d",&ch_m);
        gotoxy(1,30);
        printf(" ");
        switch(ch_m)
        {
            case 1:

                do
                {
                    gameover=0;
                    Border();
                    for(int i=0;i<7;i++)
                    {
                        gotoxy(x,y+i);
                        for(int j=0;j<20;j++)
                        {
                            printf("*");
                        }
                    }
                    gotoxy(x+1,y+1);
                    printf("\a1.Easy            ");
                    gotoxy(x+1,y+3);
                    printf("2.Medium          ");
                    gotoxy(x+1,y+5);
                    printf("3.Hard            ");
                    gotoxy(1,30);
                    int ch_l=0;
                    fflush(stdin);
                    scanf("%d",&ch_l);
                    gotoxy(1,30);
                    printf(" ");
                    switch(ch_l)
                    {
                        case 1:
                            level=99999999;ch_w=0;break;
                        case 2:
                            level=59999999;ch_w=0;break;
                        case 3:
                            level=39999999;ch_w=0;break;
                        default:
                            gotoxy(1,30);
                            printf("\nInvalid Choice");
                            getch();break;
                    }

                }while(ch_w);
                w1=0;
                break;

            case 2:
                w1=0;exit(0);break;
            default:
                gotoxy(1,30);
                printf("\nInvalid choice");
                getch();
        }
    }while(w1);
  //*///  return 0;
}

void Border()
{
    system("cls");
    int n=1;
    gotoxy(1,1);
    for(int i=1;i<=28;i++)
    {
        for(int j=1;j<=118;j++)
        {
            if(i==1||i==28||j==1||j==118)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        gotoxy(1,n+i);
    }
}

void Draw()
{
    system("cls");
    Border();
    for(int i=0;i<3;i++)
    {
        Draw_Block(Block_x[i],Block_y[i],l[i]);
        Block_x[i]++;
        Selectxy(i);
    }
    Score+=5;
    Draw_Heli();
    gotoxy(130,5);
    printf("Score : %d",Score);
    gotoxy(130,6);
    printf("P : PAUSE");
    gotoxy(130,7);
    printf("Esc : EXIT");
    if(((Heli_x-2<=Block_x[lc])&&(Block_x[lc]<=Heli_x+16))&&((Block_y[lc]-4<=Heli_y)&&(Heli_y<=Block_y[lc]+l[lc])))
    {
        Game_over();
    }
    //getch();
}

void Draw_Heli()
{
    gotoxy(Heli_x,Heli_y);
    printf("=====:=====");
    gotoxy(Heli_x+4,Heli_y+1);
    printf("@@@        //");
    gotoxy(Heli_x+2,Heli_y+2);
    printf("@@@@@@@@@@@@@");
    gotoxy(Heli_x+3,Heli_y+3);
    printf("@@@@@       \\\\");
    gotoxy(Heli_x+3,Heli_y+4);
    printf("/***\\");
}

void Logic()
{
    if((Heli_x==1)||(Heli_y==1)||(Heli_x==82)||(Heli_y==24))/*This is logic to show gameover when heli hits the border*/
    {
        Game_over();
    }
}

void In()
{

    fflush(stdin);
    if(kbhit())
    {
        char mv=getch();
        if(mv=='w'||mv=='W')
        {
            Heli_y-=2;
        }
        else if(mv=='s'||mv=='S')
        {
            Heli_y+=2;
        }
        else if (mv=='p'||mv=='P')
        {
            gotoxy(53,14);
            printf("##########");
            gotoxy(53,15);
            printf("##########");
            gotoxy(53,16);
            printf("##########");
            gotoxy(55,15);
            printf("\aPAUSED");
            gotoxy(0,30);
            getch();
            printf("\a");
        }
        else if(mv==27)
        {
            exit(0);
        }
        else
        {
            Heli_y++;
        }
    }
    else
    {
        Heli_y++;
    }
    Delay();
     /*Easy=99999999*/      /*Medium=59999999*/    /*Hard=39999999*/    /*Hard2=19999999*/
}

void Delay()
{
    for(int i=1;i<level;i++);
}

void Draw_Block(int X,int Y,int l)
{
    gotoxy(X,Y);
    for(int i=1;i<=l;i++)
    {
        printf("@@@@");
        gotoxy(X,Y+i);
    }
}

void Selectxy(int i)
{
    if(Block_x[i]>114)
    {
        lc=(i+1)%5;
        Block_x[i]=3;
        for(;;)
        {
            Block_y[i]=rand()%28;
            if(Block_y[i]<20&&Block_y[i]>0&&(Block_y[i]-Block_y[i-1]>5||Block_y[i-1]-Block_y[i]>5))
            {
                break;
            }
        }
        if(i%2==0)
        {
            if(Block_y[i]<5&&Block_y[i]>0)
            {
                Block_y[i]=2;
            }
            if(Block_y[i]<20&&Block_y[i]>14)
            {
                Block_y[i]=19;
            }
        }
        for(;;)
        {
            l[i]=rand()%10;
            if(l[i]>5&&l[i]<10)
            {
                break;
            }
        }
    }
}

void Game_over()
{
    gotoxy(53,14);
    printf("##########");
    gotoxy(53,15);
    printf("##########");
    gotoxy(53,16);
    printf("##########");
    gotoxy(54,15);
    printf("GameOver\a");
    gotoxy(0,30);
   // getch();
    for(int i=0;i<5555;i++);
    gotoxy(130,8);
    printf("Press Any Key");
    getch();
    gameover=1;
}

void Show_Score()
{
    system("cls");
    gotoxy(53,15);
    printf("Your score was : %d",Score);
    getch();
}
