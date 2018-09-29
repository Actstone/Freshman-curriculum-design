#include<stdio.h>
#include"console.h"

void graph_rectangle(int x,int y,int w,int h)   //矩形
{
    int i,j;
    fromxy(x,y);
    printf("╔");
    for(i=w-2;i>0;i--)
    {
        printf("═");
    }
    printf("╗");
    for(i=1;i<=h-2;i++)
    {
        fromxy(x,y+i);
        printf("║");
        for(j=1;j<=w-2;j++)
        {
            printf("  ");
        }
        printf("║");
    }
    fromxy(x,y+i);
    printf("╚");
    for(i=w-2;i>0;i--)
    {
        printf("═");
    }
    printf("╝");
}

void graph_Star(int x,int y,int w,int h)  //星矩形
{
    int i,j;
    fromxy(x,y);
    printf("*");
    for(i=w-1;i>0;i--)
    {
        printf("*");
    }
    printf("*");
    for(i=1;i<=h-1;i++)
    {
        fromxy(x,y+i);
        printf("*");
        for(j=1;j<=w-1;j++)
        {
            printf(" ");
        }
        printf("*");
    }
    fromxy(x,y+i);
    printf("*");
    for(i=w-1;i>0;i--)
    {
        printf("*");
    }
    printf("*");
}

void graph_and(int x,int y,int w,int h)   //&矩形
{
    int i,j;
    fromxy(x,y);
    printf("&");
    for(i=w-1;i>0;i--)
    {
        printf("&");
    }
    printf("&");
    for(i=1;i<=h-1;i++)
    {
        fromxy(x,y+i);
        printf("&");
        for(j=1;j<=w-1;j++)
        {
            printf(" ");
        }
        printf("&");
    }
    fromxy(x,y+i);
    printf("&");
    for(i=w-1;i>0;i--)
    {
        printf("&");
    }
    printf("&");
}

void graph_Hline(int x,int y,int lengh)  //横线
{
    int i;
    fromxy(x,y);
    for(i=1;i<=lengh;i++)
        printf("═");
}

void graph_Sline(int x,int y,int lengh)   //竖线
{
    int i;
    for(i=0;i<lengh;i++)
    {
        fromxy(x,y+i);
        printf("║");
    }
}

void graph_1(int x,int y)
{
    fromxy(x,y);
    printf("╔");
}

void graph_2(int x,int y)
{
    fromxy(x,y);
    printf("╦");
}

void graph_3(int x,int y)
{
    fromxy(x,y);
    printf("╗");
}

void graph_4(int x,int y)
{
    fromxy(x,y);
    printf("╠");
}

void graph_5(int x,int y)
{
    fromxy(x,y);
    printf("╬");
}

void graph_6(int x,int y)
{
    fromxy(x,y);
    printf("╣");
}

void graph_7(int x,int y)
{
    fromxy(x,y);
    printf("╚");
}

void graph_8(int x,int y)
{
    fromxy(x,y);
    printf("╩");
}

void graph_9(int x,int y)
{
    fromxy(x,y);
    printf("╝");
}

void graph_10(int x,int y)
{
    fromxy(x,y);
    printf("║");
}

void graph_point(int x,int y,int lenth)   //横线
{
    int i;
    fromxy(x,y);
    for(i=1;i<=lenth;i++)
        printf("┄");
}

void graph_arrow(void)    //箭头
{
    fromxy(53,13);printf("        ◣");
    fromxy(53,14);printf("        ▇◣");
    fromxy(53,15);printf("▇▇▇▇▇▇◣");
    fromxy(53,16);printf("▇▇▇▇▇▇◤");
    fromxy(53,17);printf("        ▇◤");
    fromxy(53,18);printf("        ◤");
}

