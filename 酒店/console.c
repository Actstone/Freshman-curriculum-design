#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

HANDLE hConsole = NULL;

void initConsole(void)  //初始化控制台
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == NULL) {
        fprintf(stderr, "初始化错误：无法获取控制台句柄\n");
        exit(1);
    }
    SetConsoleTitle("控制台1");
    COORD size = {120, 30};  // 设置控制台缓冲
    SetConsoleScreenBufferSize(hConsole,size);
    SMALL_RECT rc =  {0, 0, 119, 29};  // 长宽的最大值为缓冲区减1
    SetConsoleWindowInfo(hConsole, true, &rc);
}

void fromxy(int x, int y)   //定位光标
{
  COORD scrn;
  scrn.X = x; scrn.Y = y;
  SetConsoleCursorPosition(hConsole,scrn);
}

void setColor(unsigned short color)  //改变颜色
{
    SetConsoleTextAttribute(hConsole,color);
}

void clearColor(void)   //恢复颜色
{
    setColor(0x0f);
}

void clearScreen(void)   //清屏
{
    system("cls");
}

void destroyConsole(void)  //释放控制台变量
{
    CloseHandle(hConsole);
}

void Scanf_d(int x,int y,int *d)
{
    fromxy(x,y);
    scanf("%d",d);
}

void Scanf_s(int x,int y,char *s)
{
    fromxy(x,y);
    scanf("%s",s);
}

void hideCursor(void)    //隐藏光标
{
    CONSOLE_CURSOR_INFO a = {1, 0};
    SetConsoleCursorInfo(hConsole, &a);
}

void showCursor(void)   //显示光标
{
    CONSOLE_CURSOR_INFO a = {100, 1};
    SetConsoleCursorInfo(hConsole, &a);
}



