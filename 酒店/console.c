#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

HANDLE hConsole = NULL;

void initConsole(void)  //��ʼ������̨
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == NULL) {
        fprintf(stderr, "��ʼ�������޷���ȡ����̨���\n");
        exit(1);
    }
    SetConsoleTitle("����̨1");
    COORD size = {120, 30};  // ���ÿ���̨����
    SetConsoleScreenBufferSize(hConsole,size);
    SMALL_RECT rc =  {0, 0, 119, 29};  // ��������ֵΪ��������1
    SetConsoleWindowInfo(hConsole, true, &rc);
}

void fromxy(int x, int y)   //��λ���
{
  COORD scrn;
  scrn.X = x; scrn.Y = y;
  SetConsoleCursorPosition(hConsole,scrn);
}

void setColor(unsigned short color)  //�ı���ɫ
{
    SetConsoleTextAttribute(hConsole,color);
}

void clearColor(void)   //�ָ���ɫ
{
    setColor(0x0f);
}

void clearScreen(void)   //����
{
    system("cls");
}

void destroyConsole(void)  //�ͷſ���̨����
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

void hideCursor(void)    //���ع��
{
    CONSOLE_CURSOR_INFO a = {1, 0};
    SetConsoleCursorInfo(hConsole, &a);
}

void showCursor(void)   //��ʾ���
{
    CONSOLE_CURSOR_INFO a = {100, 1};
    SetConsoleCursorInfo(hConsole, &a);
}



