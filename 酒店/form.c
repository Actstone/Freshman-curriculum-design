#include<stdio.h>
#include"console.h"
#include<time.h>
#include <stdbool.h>
#include<stdlib.h>

int main()
{
    int m;
    char n;
    initConsole();
    hideCursor();
    Client_head=data_client_read();
    form_first_head();
    form_first_option();
    special_first_botton();
    destroyConsole();
    return 0;
}

void  form_menu(void)   //�˵����
{
    fromxy(1,1);sentence_4();
    graph_1(11,2);graph_2(69,2);graph_3(99,2);
    graph_4(11,4);graph_5(69,4);graph_6(99,4);
    graph_7(11,17);graph_8(69,17);graph_9(99,17);
    graph_Hline(13,4,28);graph_Hline(13,17,28);graph_Hline(71,17,14);
    graph_Hline(13,2,28);graph_Hline(71,2,14);graph_Hline(71,4,14);
    graph_Sline(11,3,1);graph_Sline(69,3,1);graph_Sline(99,3,1);
    graph_Sline(11,5,12);graph_Sline(69,5,12);graph_Sline(99,5,12);
    graph_point(13,3,12);printf("<�˵�>");graph_point(43,3,13);
    graph_point(71,3,5);printf("<��Ʒ>");graph_point(87,3,6);
    graph_rectangle(11,17,45,10);
    graph_4(11,17);graph_8(69,17);graph_6(99,17);
    graph_Sline(19,18,8);
    fromxy(15,19);printf("��");fromxy(15,21);printf("��");fromxy(15,23);printf("��");
    graph_2(19,17);graph_8(19,26);
    fromxy(50,27);printf("���ո��ȷ��");
}

void form_foodpay(int M)   //�˵�֧������
{
    graph_rectangle(35,9,23,10);
    graph_Star(37,10,41,7);
    fromxy(50,12);printf("����Ҫ֧��%dԪ",M);
    setColor(0x3b);fromxy(47,15);printf("ȷ��֧��(y)");
    fromxy(60,15);printf("ȡ��֧��(n)");
}

void form_roompay(int price)   //�Ǽ�ע�����
{
    int rom;
    struct Client *r;
    graph_rectangle(35,9,23,10);
    graph_Star(37,10,41,7);
    while(1){
    fromxy(47,13);printf("�����뷿���:    ");fromxy(60,13);
    Client_head=data_client_read();
    r=data_find_room(Client_head);
    if(r!=NULL){r->food+=price;data_client_write(Client_head);break;}
    else {fromxy(53,14);printf("�޸÷���!");}
    }
    clearColor();
}

void form_order_success(void)
{
    graph_rectangle(35,9,23,10);
    graph_Star(37,10,41,7);
    fromxy(46,12);printf("���Ǵ����ʼ����");
    fromxy(52,14);printf("�Ժ��͵����ķ��䡤������");
    fromxy(50,16);printf("(�����������)");
}

void form_room(void)   //ʣ�෿����ʾ����
{
    fromxy(1,1);sentence_3();
    graph_rectangle(11,2,47,3);
    graph_rectangle(11,4,47,3);
    graph_rectangle(11,6,47,3);
    graph_rectangle(11,8,47,3);
    graph_rectangle(11,10,47,3);
    graph_4(11,4);graph_4(11,6);graph_4(11,8);graph_4(11,10);
    graph_6(103,4);graph_6(103,6);graph_6(103,8);graph_6(103,10);
    graph_2(29,2);graph_5(29,4);graph_5(29,6);graph_5(29,8);graph_5(29,10);
    graph_8(29,12);graph_10(29,3);graph_10(29,5);graph_10(29,7);
    graph_10(29,9);graph_10(29,11);
    fromxy(17,3);printf("��������");fromxy(60,3);printf("ʣ�෿��");
    fromxy(13,5);printf("��ͳ�׷�(600/��)");
    fromxy(14,7);printf("������(300/��)");
    fromxy(14,9);printf("����(200/��)");
    fromxy(14,11);printf("��׼��(100/��)");
    setColor(0x70);fromxy(45,14);printf("��ס(y)");
    fromxy(65,14);printf("ȡ��(n)");
    clearColor();
}

void form_checkin(void)   //�Ǽ��������
{
    fromxy(14,14);printf("                                        ��Ϣ�Ǽ�                      ");
    graph_rectangle(33,15,26,11);
    graph_point(35,17,24);graph_point(35,19,24);
    graph_point(35,21,24);graph_point(35,23,24);
    fromxy(39,16);printf("����:");
    fromxy(39,18);printf("�绰:");
    fromxy(35,20);printf("���֤��:");
    fromxy(39,22);printf("����:");
    fromxy(35,24);printf("��ס����:");
    setColor(0x70);fromxy(53,26);printf("ȷ ��(Enter)");clearColor();
}

void form_checkSuccess(void)    //�Ǽǳɹ�����
{
    setColor(0x3b);
    graph_rectangle(40,18,20,4);
    fromxy(54,19);printf("Ԥ���ɹ�!!!");
    fromxy(53,20);printf("�����������");
    clearColor();
}

int form_call(void)   //���н���
{
    fromxy(1,1);sentence_5();
    int form_call_room;
    setColor(0x3b);graph_rectangle(40,10,20,10);graph_Star(42,11,35,7);
    fromxy(51,12);printf("�����뷿���:");
    scanf("%d",&form_call_room);
    clearColor();
    return(form_call_room);
}

void form_callsuccess(void)   //���гɹ�����
{
    setColor(0x3b);
    fromxy(52,14);printf("����Ա���Ͼ͵�...");
    fromxy(52,16);printf("(�����������)");
    clearColor();
}

void form_inname(void)   //��ѯ����
{
    setColor(0x70);graph_rectangle(44,3,15,3);
    fromxy(50,4);printf("����������:");
    clearColor();
}

void form_incard(void)
{
    setColor(0x70);graph_rectangle(44,3,19,3);
    fromxy(47,4);printf("���������֤:");
    clearColor();
}

void form_inroom(void)
{
    setColor(0x70);graph_rectangle(44,3,15,3);
    fromxy(50,4);printf("�����뷿��:");
    clearColor();
}

void form_findresult(struct Client *pp)     //��ѯ�����
{
    setColor(0x70);
    graph_rectangle(16,8,17,17);
    graph_point(18,10,15);graph_point(18,12,15);
    graph_point(18,14,15);graph_point(18,16,15);
    graph_point(18,18,15);graph_point(18,20,15);
    graph_point(18,22,15);
    fromxy(22,9);printf("����: %s",pp->name);
    fromxy(18,11);printf("���֤��: %s",pp->card);
    fromxy(22,13);printf("�绰: %s",pp->tel);
    fromxy(22,15);printf("����: %d",pp->room);
    fromxy(22,17);printf("����: %d",pp->hotel);
    fromxy(22,19);printf("�ͷ�: %d",pp->food);
    fromxy(18,21);printf("��ס����: %d-%d-%d",pp->start.year,pp->start.month,pp->start.day);
    fromxy(18,23);printf("����ʱ��: %d-%d-%d",pp->finish.year,pp->finish.month,pp->finish.day);
    fromxy(43,26);printf("�� ��(r)");
   // fromxy(55,26);printf("ɾ ��(d)");
    fromxy(67,26);printf("�� ��(b)");
    clearColor();
}

void form_modification(void)  //�޸���Ϣ����
{
    setColor(0x70);
    graph_rectangle(70,8,17,17);
    graph_point(72,10,15);graph_point(72,12,15);
    graph_point(72,14,15);graph_point(72,16,15);
    graph_point(72,18,15);graph_point(72,20,15);
    graph_point(72,22,15);
    fromxy(76,9);printf("����:");
    fromxy(72,11);printf("���֤��:");
    fromxy(76,13);printf("�绰:");
    fromxy(76,15);printf("����:");
    fromxy(76,17);printf("����:");
    fromxy(76,19);printf("�ͷ�:");
    fromxy(72,21);printf("��ס����:     -  -");
    fromxy(72,23);printf("����ʱ��:     -  -");
    fromxy(55,26);printf("ȷ��(Enter)");
    clearColor();
    fromxy(43,26);printf("        ");
    fromxy(67,26);printf("        ");
}

void form_delete(void)
{
    setColor(0x70);
    graph_rectangle(44,15,15,3);
    fromxy(54,16);printf("ɾ���ɹ�����");
    clearColor();
}

void form_reserve(void)
{
    setColor(0x70);
    graph_rectangle(44,15,15,3);
    fromxy(54,16);printf("�޸ĳɹ�����");
    clearColor();
}

void form_copyfile(void)    //���ݽ���
{
    clearScreen();
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(53,9);printf("������...");
    form_5s(62,9);
    clearColor();
}

void form_copysuccess(void)
{
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(53,9);printf("���ݳɹ���");
    clearColor();
}

void form_cover(void)    //ϵͳ�޸�����
{
    clearScreen();
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(49,9);printf("ϵͳ�ָ���...");
    form_5s(62,9);
    clearColor();
}

void form_coversuccess(void)
{
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(53,9);printf("�ָ��ɹ���");
    clearColor();
}

void form_back(void)   //�˶�����
{
    setColor(0x70);graph_rectangle(44,3,15,3);
    fromxy(50,4);printf("����������:");
    clearColor();
}

void form_backInformation(struct Client *p)  //�˶���Ϣ��ʾ
{
    setColor(0x70);
    graph_rectangle(44,11,15,9);
    graph_point(46,13,13);
    graph_point(46,15,13);
    graph_point(46,17,13);
    fromxy(46,12);printf("����:%s",p->name);
    fromxy(46,14);printf("����:%d",p->room);
    fromxy(46,16);printf("����:%d",p->hotel);
    fromxy(46,18);printf("�ͷ�:%d",p->food);
    fromxy(48,21);printf("ȷ���˶�(y)");
    fromxy(62,21);printf("�� ��(n)");
    clearColor();
}

void form_repay(struct Client *p)
{
    setColor(0x70);
    graph_rectangle(40,9,20,5);
    fromxy(50,10);printf("ȷ�ϸ���:��%dԪ!!!",p->hotel+p->food);
    clearColor();
    fromxy(52,12);printf("ȷ��(y)");
    fromxy(62,12);printf("ȡ��(n)");
}

void form_repaysuccess(void)
{
    setColor(0x70);
    graph_rectangle(40,9,20,5);
    fromxy(50,10);printf("     ����ɹ�    ");
    fromxy(52,12);printf("�����������");clearColor();
}

void form_repayfault(void)
{
    setColor(0x70);
    graph_rectangle(40,9,20,5);
    fromxy(50,10);printf("     ����ʧ��    ");
    fromxy(52,12);printf("�����������");clearColor();
}

void form_first_head(void)   //������
{
    clock_t start,finish;
    double elapsed_time,a=0,b=500;
    start=finish=clock();
    elapsed_time=finish-start;
    while(elapsed_time<=4200)
    {
        finish=clock();
        elapsed_time=finish-start;
        if(elapsed_time-a>1000)
           {
            setColor(0x6e);
            graph_Star(42,6,31,4);a=elapsed_time;
            fromxy(48,8);printf("��ӭ����xxx��Ƶ꣡");
           }
        else if(elapsed_time-b>1000)
            {
            setColor(0x2a);
            graph_and(42,6,31,4);b=elapsed_time;
            fromxy(48,8);printf("��ӭ����xxx��Ƶ꣡");
            }
        clearColor();
    }
}

void form_5s(int x,int y)   //5�뵹��ʱ
{
    long a,b;
    int i=0;
    a=b=time(NULL);
    while((b-a)<3)
    {
        b=time(NULL);
        if((b-a)==(1+i))
        {
            fromxy(x,y);
            printf("(%ld)",b-a);
            i++;
        }
    }
}

void form_first_option(void)   //�����涯��
{
    clock_t start,finish;
    double cha;
    int x,y;
    start=finish=clock();
    cha=finish-start;
    x=(int)(cha/25);
    y=x-1;
    while(x<=9)
    {
        switch(x)
        {
            case 0:if(x==y) break;
                   else {form_first_option_1();y=x;break;}
            case 1:if(x==y) break;
                   else {form_first_option_2();y=x;break;}
            case 2:if(x==y) break;
                   else {form_first_option_3();y=x;break;}
            case 3:if(x==y) break;
                   else {form_first_option_4();y=x;break;}
            case 4:if(x==y) break;
                   else {form_first_option_5();y=x;break;}
            case 5:if(x==y) break;
                   else {form_first_option_6();y=x;break;}
            case 6:if(x==y) break;
                   else {form_first_option_7();y=x;break;}
            case 7:if(x==y) break;
                   else {form_first_option_8();y=x;break;}
            case 8:if(x==y) break;
                   else {form_first_option_9();y=x;break;}
            case 9:if(x==y) break;
                   else {form_first_option_10();y=x;break;}
        }
        finish=clock();cha=finish-start;x=(int)(cha/25);
    }
}

void form_first_option_1(void)
{
    setColor(0x3b);graph_Star(42,11,31,1);clearColor();
}

void form_first_option_2(void)
{
    setColor(0x3b);graph_Star(42,11,31,2);
    fromxy(53,11);setColor(0xb0);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_3(void)
{
    setColor(0x3b);graph_Star(42,11,31,3);
    fromxy(53,12);setColor(0xb0);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_4(void)
{
    setColor(0x3b);graph_Star(42,11,31,4);
    setColor(0xb0);
    fromxy(53,11);printf("�� ��  �� ");
    fromxy(53,13);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_5(void)
{
    setColor(0x3b);graph_Star(42,11,31,5);
    setColor(0xb0);
    fromxy(53,12);printf("�� ��  �� ");
    fromxy(53,14);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_6(void)
{
    setColor(0x3b);graph_Star(42,11,31,6);
    setColor(0xb0);
    fromxy(53,11);printf("�� ����Ա ");
    fromxy(53,13);printf("�� ��  �� ");
    fromxy(53,15);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_7(void)
{
    setColor(0x3b);graph_Star(42,11,31,7);
    setColor(0xb0);
    fromxy(53,12);printf("�� ����Ա ");
    fromxy(53,14);printf("�� ��  �� ");
    fromxy(53,16);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_8(void)
{
    setColor(0x3b);graph_Star(42,11,31,8);
    setColor(0xb0);
    fromxy(53,11);printf("�� ��  �� ");
    fromxy(53,13);printf("�� ����Ա ");
    fromxy(53,15);printf("�� ��  �� ");
    fromxy(53,17);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_9(void)
{
    setColor(0x3b);graph_Star(42,11,31,9);
    setColor(0xb0);
    fromxy(53,12);printf("�� ��  �� ");
    fromxy(53,14);printf("�� ����Ա ");
    fromxy(53,16);printf("�� ��  �� ");
    fromxy(53,18);printf("�� ��  �� ");
    clearColor();
}

void form_first_option_10(void)
{
    setColor(0x3b);graph_Star(42,11,31,10);
    setColor(0xb0);
    fromxy(53,13);printf("�� ��  �� ");
    fromxy(53,15);printf("�� ����Ա ");
    fromxy(53,17);printf("�� ��  �� ");
    fromxy(53,19);printf("�� ��  �� ");
    clearColor();
}

void form_safe(void)
{
    clearScreen();
    setColor(0x3b);
    graph_rectangle(44,10,15,3);
    fromxy(50,11);printf("����������:");
    clearColor();
}

void form_remind(void)
{
    clearScreen();
    setColor(0x70);
    graph_rectangle(44,13,15,3);
    fromxy(50,14);printf("    �ŷ�����з��ܣ�");
    clearColor();
}

void form_password(void)    //����Ա��������
{
    clearScreen();
    setColor(0x3b);graph_rectangle(44,8,15,3);
    fromxy(48,9);printf("���������Ա����:");
    clearColor();
}

