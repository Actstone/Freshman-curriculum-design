#include<stdio.h>
#include <stdbool.h>
#include"console.h"
#include<time.h>
#include<stdlib.h>

char *Menu[15]={"�������","��������","�ͱ����",
                "���պ���","��������","�ع���  ",
                "������˿","������  ","ţ����  ",
                "�׷�    ","ơ��    ","����ˮ  ",
                "�׿�ˮ  ","��ʿ��  ","����    "};
int Price[15]={80,100,130,70,80,45,55,30,15,2,5,5,100,1000,10};


state special_init(int x,int y,unsigned short color1,unsigned short color2,char *text)  //Ϊѡ�����ֵ
{
    state answer = (state)malloc(sizeof(struct State));
    answer->x=x;
    answer->y=y;
    answer->color1=color1;
    answer->color2=color2;
    answer->text=text;
    answer->selected=false;
    return answer;
}

void special_setSelect(state a)  //�ı�ѡ��״̬
{
    a->selected=true;
};

void special_removeSelect(state a)  //��ԭѡ��״̬
{
    a->selected=false;
}

int special_getKey(void)  //��ü���
{
    int i;
    i=getch();
    if(i==224)
    {
        i=getch();
        if(i==72) return(-72);
        else if(i==80) return(-80);
        else if(i==75) return(-75);
        else if(i==77) return(-77);
    }
    else if(i==13) return(13);
    else if(i==32) return(32);
    else if(i==8) return(8);
}

void special_printfstate(state b)   //���������ѡ��
{
    fromxy(b->x,b->y);
    if(b->selected)      //����ͬ����ֵ�����ͬ����ɫ
    {
        setColor(b->color1);
        printf("%s",b->text);
        fromxy(b->x,b->y);
        printf("��");
    }
    else
    {
        setColor(b->color2);
        printf("%s",b->text);
    }
    clearColor();
}

void special_second_botton(void)  //�˿Ͳ˵�
{
    bool quit = false;
    int i,Focus = 0;
    state OPTION[4];
    OPTION[0] = special_init(53,13,0x90,0xb0,"�� Ԥ  �� ");   //Ϊѡ�ֵ
    OPTION[1] = special_init(53,15,0x90,0xb0,"�� ��  �� ");
    OPTION[2] = special_init(53,17,0x90,0xb0,"�� ��  �� ");
    OPTION[3] = special_init(53,19,0x90,0xb0,"�� ��  �� ");
    OPTION[0]->selected=true;
    setColor(0x3b);
      graph_Star(42,6,31,4);
      fromxy(48,8);printf("��ӭ����xxx��Ƶ꣡");
      setColor(0x3b);graph_Star(42,11,31,10);clearColor();
    while(!quit)
    {
      clearColor();fromxy(1,1);sentence_2();
      for(i=0;i<4;i++)
          special_printfstate(OPTION[i]);
      int ch=special_getKey();
      if (ch == -80)   //��Ϊ����� �¼�
      {
          if (Focus == 3);
          else
          {
          special_removeSelect(OPTION[Focus]);
          Focus++;
          special_setSelect(OPTION[Focus]);
          }
      }
      if(ch==-72)   //��Ϊ������ϼ�
      {
          if(Focus<=0);
          else
          {
              special_removeSelect(OPTION[Focus]);
              Focus--;
              special_setSelect(OPTION[Focus]);
          }
      }
      if(ch==13)   //��ΪEnter��
          {
            if(Focus==0)
            {
                int a;
                clearScreen();
                form_room();
                data_restroom();
                a=getch();
                while(1)
                {
                    if(a=='y')
                    {
                        form_checkin(); data_checkin();
                        int b=special_getKey();
                        while(1)
                        {
                            if(b==13) {clearScreen();form_checkSuccess();a=getch();clearScreen();break;}
                            else {b=special_getKey();}
                        }
                        break;
                    }
                    else if(a=='n') {clearScreen();break;}
                    a=getch();
                }
                 setColor(0x3b);
                 graph_Star(42,6,31,4);
                 fromxy(48,8);printf("��ӭ����xxx��Ƶ꣡");
                 setColor(0x3b);graph_Star(42,11,31,10);
                 continue;
            }
            if(Focus==1)
            {
                clearScreen();
                form_menu();
                special_menu();
                clearScreen();
                setColor(0x3b);
                graph_Star(42,6,31,4);
                fromxy(48,8);printf("��ӭ����xxx��Ƶ꣡");
                setColor(0x3b);graph_Star(42,11,31,10);
                continue;
            }
            if(Focus==2)
            {
                clearScreen();
                data_call_write(form_call());
                form_callsuccess();
                char t=getch();
                clearScreen();
                setColor(0x3b);
                graph_Star(42,6,31,4);
                fromxy(48,8);printf("��ӭ����xxx��Ƶ꣡");
                setColor(0x3b);graph_Star(42,11,31,10);
                continue;
            }
            if(Focus==3)
            {
                break;
            }
          }
    }
     for(i=0;i<4;i++)
        free(OPTION[i]);

}

void special_flycome(int x,int y,unsigned short color,int Start,int Finish,char *text)  //ѡ���
{
    clock_t start,finish;
    double cha;
    int a,b;
    start=finish=clock();
    cha=finish-start;
    a=(int)(cha/20);
    b=a-1;
    while(a<20)
    {
        if(a!=b)
        {
            fromxy(x+a,y);setColor(0x3b);printf(" ");
            setColor(color);
            printf("%s",text);
            if(x+a<Start)
            {
                setColor(0x00);fromxy(x+a,y);
                for(int i=0;i<Start-(x+a);i++)
                    printf(" ");
            }
            clearColor();b=a;
        }
        finish=clock();
        cha=finish-start;
        a=(int)(cha/20);
    }
}

void special_flygo(int x,int y,unsigned short color,int lenth,int Finish,char *text)
{
    clock_t start,finish;
    double cha;
    int a,b;
    start=finish=clock();
    cha=finish-start;
    a=(int)(cha/20);
    b=a-1;
    while(a<21)
    {
        if(a!=b)
        {
            fromxy(x+a,y);setColor(0x3b);printf(" ");
            setColor(color);
            printf("%s",text);
            if(x+a+lenth>Finish)
            {
                setColor(0x00);fromxy(Finish,y);
                printf("          ");
            }
            clearColor();b=a;
        }
        finish=clock();
        cha=finish-start;
        a=(int)(cha/20);
    }
}

void special_first_botton(void)   //������˵�
{

    bool quit = false;
    int i,focus = 0;
    state OPTION[4];
    OPTION[0] = special_init(53,13,0x90,0xb0,"�� ��  �� ");
    OPTION[1] = special_init(53,15,0x90,0xb0,"�� ����Ա ");
    OPTION[2] = special_init(53,17,0x90,0xb0,"�� ��  �� ");
    OPTION[3] = special_init(53,19,0x90,0xb0,"�� ��  �� ");
    OPTION[0]->selected=true;
    while(!quit)
    {
      fromxy(1,1);sentence_1();printf("                            ");
      for(i=0;i<4;i++)
          special_printfstate(OPTION[i]);
      int ch=special_getKey();
      if (ch == -80)
      {
          if (focus == 3);
          else
          {
          special_removeSelect(OPTION[focus]);
          focus++;
          special_setSelect(OPTION[focus]);
          }
      }
      if(ch==-72)
      {
          if(focus<=0);
          else
          {
              special_removeSelect(OPTION[focus]);
              focus--;
              special_setSelect(OPTION[focus]);
          }
      }
      if(ch==13)
      {
              if(focus==0)
              {
                special_flygo(53,13,0xb0,10,74,"�� ��  �� ");
                special_flygo(53,15,0xb0,10,74,"�� ����Ա ");
                special_flygo(53,17,0xb0,10,74,"�� ��  �� ");
                special_flygo(53,19,0xb0,10,74,"�� ��  �� ");
                special_flycome(33,13,0xb0,42,90,"�� Ԥ  �� ");
                special_flycome(33,15,0xb0,42,90,"�� ��  �� ");
                special_flycome(33,17,0xb0,42,90,"�� ��  �� ");
                special_flycome(33,19,0xb0,42,90,"�� ��  �� ");
                special_second_botton();
                continue;
              }
              if(focus==1)
              {
                  form_password();
                  data_password();
                  special_third_botton();
                  clearScreen();
                  setColor(0x3b);graph_Star(42,11,31,10);clearColor();
                  setColor(0x3b);
                  graph_Star(42,6,31,4);
                  fromxy(48,8);printf("��ӭ����xxx��Ƶ꣡");
                  setColor(0x3b);graph_Star(42,11,31,10);clearColor();
              }
              if(focus==2)
                system("notepad file/help.txt");
              if(focus==3)
                break;
       }
    }
     for(i=0;i<4;i++)
        free(OPTION[i]); //�ͷŽṹ��ָ��
}

void special_third_botton(void)   //����Ա�˵�
{
    setColor(0x3b);graph_rectangle(42,10,16,13);
    bool quit = false;
    int i,Focus = 0;
    state OPTION[5];
    OPTION[0] = special_init(53,12,0x90,0xb0,"�� ��  ѯ ");
    OPTION[1] = special_init(53,14,0x90,0xb0,"�� ��  �� ");
    OPTION[2] = special_init(53,16,0x90,0xb0,"�� ��  �� ");
    OPTION[3] = special_init(53,18,0x90,0xb0,"�� ��  �� ");
    OPTION[4] = special_init(53,20,0x90,0xb0,"�� ��  �� ");
    OPTION[0]->selected=true;
    while(!quit)
    {
      fromxy(1,1);clearColor();sentence_6();
      for(i=0;i<5;i++)
          special_printfstate(OPTION[i]);
      int ch=special_getKey();
      if (ch == -80)
      {
          if (Focus == 4);
          else
          {
          special_removeSelect(OPTION[Focus]);
          Focus++;
          special_setSelect(OPTION[Focus]);
          }
      }
      else if(ch==-72)
      {
          if(Focus<=0);
          else
          {
              special_removeSelect(OPTION[Focus]);
              Focus--;
              special_setSelect(OPTION[Focus]);
          }
      }
      else if(ch==13)
          {
              if(Focus==0)
              {
                special_find_botton();
                setColor(0x3b);graph_rectangle(42,10,16,13);
              }
              if(Focus==1)
              {
                form_copyfile();
                form_copysuccess();fromxy(1,24);setColor(0x0);
                system("copy /y file\\client.txt file\\fclient.txt");   //ϵͳ���� �����ļ�
                system("copy /y file\\restroom.txt file\\frestroom.txt");
                system("copy /y file\\rooming.txt file\\frooming.txt");
                system("copy /y file\\call.txt file\\fcall.txt");
                getch();
                clearScreen();
                setColor(0x3b);graph_rectangle(42,10,16,13);
              }
              if(Focus==2)
              {
                form_cover();
                form_coversuccess();
                fromxy(1,24);setColor(0x0);
                system("copy /y file\\fclient.txt file\\client.txt");
                system("copy /y file\\frestroom.txt file\\restroom.txt");
                system("copy /y file\\frooming.txt file\\rooming.txt");
                system("copy /y file\\fcall.txt file\\call.txt");
                getch();
                clearScreen();
                setColor(0x3b);graph_rectangle(42,10,16,13);
              }
              if(Focus==3)
              {
                clearScreen();
                form_back();
                struct Client *medio;
                fromxy(1,1);clearColor();sentence_14();
                do
                {
                    fromxy(62,4);
                    medio=data_find_name(Client_head);  //ͨ�����ֲ��ң����ض�Ӧ�ṹ��ָ��
                    if(medio==NULL)
                    {
                        clearColor();fromxy(75,4);printf("�޸ù˿ͣ�");
                        fromxy(62,4);setColor(0x3b);printf("        ");
                    }
                    else
                    {
                        clearColor();fromxy(75,4);printf("          ");
                    }
                }while(medio==NULL);
                form_backInformation(medio);

                while(1)
                {
                    char r=getch();
                    if(r=='y')
                    {
                        form_repay(medio);
                        while(1)
                        {
                           r=getch();
                           if(r=='y')
                           {
                               rest_head=data_restroom_read();
                               struct REST *ii=rest_head;
                               while(ii->next!=NULL)
                               {
                                   ii=ii->next;
                               }
                               ii->room=medio->room;ii->ty=medio->room/100;
                               ii->next=(struct REST *)malloc(sizeof(struct REST));
                               ii->next->room=0;ii->next->next=NULL;
                               data_restroom_write(rest_head);     //������д��ʣ�෿����
                               rooming_head=data_rooming_read();
                               struct Rooming *ss=data_find_rooming(rooming_head,medio->room);
                               data_deleted_rooming(ss);   //����Ϣ����ס������ɾ��
                               data_rooming_write(rooming_head);
                               data_deleted(medio);
                               data_client_write(Client_head);  //���˿���Ϣ������Ϣ�ļ���ɾ��
                               form_repaysuccess();getch();
                               break;
                           }
                           else if(r=='n')
                           {
                               form_repayfault();getch();
                               break;
                           }
                        }
                        break;
                    }
                    else if(r=='n')
                        break;
                }
                clearScreen();
                setColor(0x3b);graph_rectangle(42,10,16,13);
              }
              if(Focus==4)
                break;
          }
     }     //else continue;
     for(i=0;i<5;i++)
        free(OPTION[i]);

}

void special_menu(void)   //��˲˵�
{
    int X=23,Y=19;
    int price=0;
    int all=0,ALL=0;
    bool quit = false;
    int i,FOCUS = -1;
    state OPTION[15];
    OPTION[0] = special_init(16,6,0x6e,0xf,"1. ������� 80  RMB");
    OPTION[1] = special_init(16,8,0x6e,0xf,"2. �������� 100 RMB");
    OPTION[2] = special_init(16,10,0x6e,0xf,"3. �ͱ���� 130 RMB");
    OPTION[3] = special_init(16,12,0x6e,0xf,"4. ���պ��� 70  RMB");
    OPTION[4] = special_init(16,14,0x6e,0xf,"5. �������� 80  RMB");
    OPTION[5] = special_init(44,6,0x6e,0xf,"6. �ع���   45  RMB");
    OPTION[6] = special_init(44,8,0x6e,0xf,"7. ������˿ 55  RMB");
    OPTION[7] = special_init(44,10,0x6e,0xf,"8. ������   30  RMB");
    OPTION[8] = special_init(44,12,0x6e,0xf,"9. ţ����   15  RMB");
    OPTION[9] = special_init(44,14,0x6e,0xf,"10.�׷�     2   RMB");
   OPTION[10] = special_init(75,6,0x6e,0xf,"11.ơ��     5   RMB");
   OPTION[11] = special_init(75,8,0x6e,0xf,"12.����ˮ   5   RMB");
   OPTION[12] = special_init(75,10,0x6e,0xf,"13.�׿�ˮ   100 RMB");
   OPTION[13] = special_init(75,12,0x6e,0xf,"14.��ʿ��  1000 RMB");
   OPTION[14] = special_init(75,14,0x6e,0xf,"15.����     10  RMB");

    while(!quit)
    {
      for(i=0;i<15;i++)
          special_printfstate(OPTION[i]);
      int ch=special_getKey();
      if (ch == -80)
      {
          if (FOCUS==14);
          else
          {
              if(FOCUS==-1)
                {
                    FOCUS+=1;
                    special_setSelect(OPTION[FOCUS]);
                    continue;
                }
          special_removeSelect(OPTION[FOCUS]);
          FOCUS++;
          special_setSelect(OPTION[FOCUS]);
          }
      }
      if(ch==-72)
      {
          if(FOCUS<=0);
          else
          {
              special_removeSelect(OPTION[FOCUS]);
              FOCUS--;
              special_setSelect(OPTION[FOCUS]);
          }
      }
      if(ch==-75)
      {
          if(FOCUS<=4);
          else
          {
              special_removeSelect(OPTION[FOCUS]);
              FOCUS-=5;
              special_setSelect(OPTION[FOCUS]);
          }
      }
      if(ch==-77)
      {
          if(FOCUS>=10);
          else if(FOCUS==-1)
          {
            FOCUS+=1;
            special_setSelect(OPTION[FOCUS]);
            continue;
          }
          else
          {
              special_removeSelect(OPTION[FOCUS]);
              FOCUS+=5;
              special_setSelect(OPTION[FOCUS]);
          }
      }
      if(ch==13)//��Ϊ�س�������Ӧλ�õ�text����ڵ����
      {
              if(ALL==18)
              {
                  X=23;Y=19;ALL=1;all=1;
                  setColor(0xe);fromxy(X,Y);
                  printf("%d.",FOCUS+1);printf("%s",Menu[FOCUS]);
                  Y+=2;price+=Price[FOCUS];
                  continue;
              }
              if(all==3)
              {
                  X+=12;Y-=6;all=1;
                  setColor(0xe);fromxy(X,Y);
                  printf("%d.",FOCUS+1);printf("%s",Menu[FOCUS]);
                  Y+=2;ALL++;price+=Price[FOCUS];
              }
              else
              {
                  setColor(0xe);fromxy(X,Y);
                  printf("%d.",FOCUS+1);printf("%s",Menu[FOCUS]);
                  Y+=2;all++;ALL++;price+=Price[FOCUS];
              }
        }
       if(ch==32)    //��Ϊ�ո�space
       {
           form_foodpay(price);
           while(1)
           {
               char o=getch();
            if(o=='y')
           {
              form_roompay(price);
              form_order_success();
              getch();
              break;
           }
           else if(o=='n') {clearColor();break;}
           else continue;
           }
           break;
       }
    }
     for(i=0;i<15;i++)
        free(OPTION[i]);

}

void special_find_botton(void)    //��Ϣ��ѯ�˵�
{
    clearScreen();setColor(0x3b);graph_rectangle(42,8,16,15);
    bool quit = false;
    int i,fo = 0;
    state OPTION[5];
    OPTION[0] = special_init(51,10,0x90,0xb0,"�� �� �� �� �� ");
    OPTION[1] = special_init(51,12,0x90,0xb0,"�� �� �� �� ѯ ");
    OPTION[2] = special_init(51,14,0x90,0xb0,"�� ���֤�Ų�ѯ");
    OPTION[3] = special_init(51,16,0x90,0xb0,"�� �� �� �� ѯ ");
    OPTION[4] = special_init(51,18,0x90,0xb0,"��   ��  ��    ");
    OPTION[0]->selected=true;
    while(!quit)
    {
      fromxy(1,1);clearColor();sentence_7();
      for(i=0;i<5;i++)
          special_printfstate(OPTION[i]);
      int ch=special_getKey();
      if (ch == -80)
      {
          if (fo == 4);
          else
          {
          special_removeSelect(OPTION[fo]);
          fo++;
          special_setSelect(OPTION[fo]);
          }
      }
      if(ch==-72)
      {
          if(fo<=0);
          else
          {
              special_removeSelect(OPTION[fo]);
              fo--;
              special_setSelect(OPTION[fo]);
          }
      }
      if(ch==13)
      {
          struct Client *v;
          if(fo==4)
            {clearScreen();break;}
          if(fo==0)
          {
              clearScreen();
              fromxy(21,3);printf("δס���䣺");
              data_restroom();
              fromxy(21,13);
              printf("��ס���䣺");
              prin(data_rooming_read());
              getch();
              clearScreen();
              setColor(0x3b);graph_rectangle(42,8,16,15);
          }
          if(fo==1)
          {
              clearScreen();
              fromxy(1,1);clearColor();sentence_8();
              setColor(0x3b);
              form_inname();
              Client_head=data_client_read();
              while(1){
                  v=data_find_name(Client_head);
                  if(v==NULL)
                  {
                      fromxy(52,7);printf("�޸ù˿�...");
                      fromxy(62,4);printf("         ");
                      fromxy(62,4);
                  }
                  else break;
              }
             clearColor();fromxy(52,7);printf("            ");
             form_findresult(v);
          }
          if(fo==2)
          {
              clearScreen();
              fromxy(1,1);clearColor();sentence_9();
              setColor(0x3b);
              form_incard();
              Client_head=data_client_read();
              while(1){
                  v=data_find_card(Client_head);
                  if(v==NULL)
                  {
                      fromxy(52,7);printf("�޸ù˿�...");
                      fromxy(60,4);printf("                  ");
                      fromxy(60,4);
                  }
                  else break;
              }
             clearColor();fromxy(52,7);printf("            ");
             form_findresult(v);
          }
          if(fo==3)
          {
              clearScreen();
              fromxy(1,1);clearColor();sentence_10();
              setColor(0x70);
              form_inroom();
              Client_head=data_client_read();
              while(1){
                  v=data_find_room(Client_head);
                  if(v==NULL)
                  {
                      fromxy(52,7);printf("�޸ù˿�...");
                      fromxy(61,4);printf("      ");
                      fromxy(62,4);
                  }
                  else break;
              }
             clearColor();fromxy(52,7);printf("            ");
             form_findresult(v);
          }
          char g=getch();
          if(g=='r')
          {
              fromxy(1,1);clearColor();sentence_12();
              graph_arrow();
              form_modification();
              data_reservein(v);
              form_reserve();
              getch();
              clearScreen();
              setColor(0x3b);graph_rectangle(42,8,16,15);
          }
          else if(g=='b'){clearScreen();setColor(0x3b);graph_rectangle(42,8,16,15);}
      }
    }
}
