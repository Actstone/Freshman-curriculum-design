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

void  form_menu(void)   //菜单表格
{
    fromxy(1,1);sentence_4();
    graph_1(11,2);graph_2(69,2);graph_3(99,2);
    graph_4(11,4);graph_5(69,4);graph_6(99,4);
    graph_7(11,17);graph_8(69,17);graph_9(99,17);
    graph_Hline(13,4,28);graph_Hline(13,17,28);graph_Hline(71,17,14);
    graph_Hline(13,2,28);graph_Hline(71,2,14);graph_Hline(71,4,14);
    graph_Sline(11,3,1);graph_Sline(69,3,1);graph_Sline(99,3,1);
    graph_Sline(11,5,12);graph_Sline(69,5,12);graph_Sline(99,5,12);
    graph_point(13,3,12);printf("<菜单>");graph_point(43,3,13);
    graph_point(71,3,5);printf("<饮品>");graph_point(87,3,6);
    graph_rectangle(11,17,45,10);
    graph_4(11,17);graph_8(69,17);graph_6(99,17);
    graph_Sline(19,18,8);
    fromxy(15,19);printf("点");fromxy(15,21);printf("菜");fromxy(15,23);printf("区");
    graph_2(19,17);graph_8(19,26);
    fromxy(50,27);printf("按空格键确认");
}

void form_foodpay(int M)   //菜单支付界面
{
    graph_rectangle(35,9,23,10);
    graph_Star(37,10,41,7);
    fromxy(50,12);printf("您需要支付%d元",M);
    setColor(0x3b);fromxy(47,15);printf("确认支付(y)");
    fromxy(60,15);printf("取消支付(n)");
}

void form_roompay(int price)   //登记注册界面
{
    int rom;
    struct Client *r;
    graph_rectangle(35,9,23,10);
    graph_Star(37,10,41,7);
    while(1){
    fromxy(47,13);printf("请输入房间号:    ");fromxy(60,13);
    Client_head=data_client_read();
    r=data_find_room(Client_head);
    if(r!=NULL){r->food+=price;data_client_write(Client_head);break;}
    else {fromxy(53,14);printf("无该房间!");}
    }
    clearColor();
}

void form_order_success(void)
{
    graph_rectangle(35,9,23,10);
    graph_Star(37,10,41,7);
    fromxy(46,12);printf("五星大厨开始备餐");
    fromxy(52,14);printf("稍后送到您的房间····");
    fromxy(50,16);printf("(按任意键返回)");
}

void form_room(void)   //剩余房间显示界面
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
    fromxy(17,3);printf("房间类型");fromxy(60,3);printf("剩余房间");
    fromxy(13,5);printf("总统套房(600/天)");
    fromxy(14,7);printf("豪华房(300/天)");
    fromxy(14,9);printf("商务房(200/天)");
    fromxy(14,11);printf("标准间(100/天)");
    setColor(0x70);fromxy(45,14);printf("入住(y)");
    fromxy(65,14);printf("取消(n)");
    clearColor();
}

void form_checkin(void)   //登记输入界面
{
    fromxy(14,14);printf("                                        信息登记                      ");
    graph_rectangle(33,15,26,11);
    graph_point(35,17,24);graph_point(35,19,24);
    graph_point(35,21,24);graph_point(35,23,24);
    fromxy(39,16);printf("姓名:");
    fromxy(39,18);printf("电话:");
    fromxy(35,20);printf("身份证号:");
    fromxy(39,22);printf("房间:");
    fromxy(35,24);printf("入住天数:");
    setColor(0x70);fromxy(53,26);printf("确 认(Enter)");clearColor();
}

void form_checkSuccess(void)    //登记成功界面
{
    setColor(0x3b);
    graph_rectangle(40,18,20,4);
    fromxy(54,19);printf("预定成功!!!");
    fromxy(53,20);printf("按任意键返回");
    clearColor();
}

int form_call(void)   //呼叫界面
{
    fromxy(1,1);sentence_5();
    int form_call_room;
    setColor(0x3b);graph_rectangle(40,10,20,10);graph_Star(42,11,35,7);
    fromxy(51,12);printf("请输入房间号:");
    scanf("%d",&form_call_room);
    clearColor();
    return(form_call_room);
}

void form_callsuccess(void)   //呼叫成功界面
{
    setColor(0x3b);
    fromxy(52,14);printf("管理员马上就到...");
    fromxy(52,16);printf("(按任意键返回)");
    clearColor();
}

void form_inname(void)   //查询界面
{
    setColor(0x70);graph_rectangle(44,3,15,3);
    fromxy(50,4);printf("请输入姓名:");
    clearColor();
}

void form_incard(void)
{
    setColor(0x70);graph_rectangle(44,3,19,3);
    fromxy(47,4);printf("请输入身份证:");
    clearColor();
}

void form_inroom(void)
{
    setColor(0x70);graph_rectangle(44,3,15,3);
    fromxy(50,4);printf("请输入房间:");
    clearColor();
}

void form_findresult(struct Client *pp)     //查询结果表
{
    setColor(0x70);
    graph_rectangle(16,8,17,17);
    graph_point(18,10,15);graph_point(18,12,15);
    graph_point(18,14,15);graph_point(18,16,15);
    graph_point(18,18,15);graph_point(18,20,15);
    graph_point(18,22,15);
    fromxy(22,9);printf("姓名: %s",pp->name);
    fromxy(18,11);printf("身份证号: %s",pp->card);
    fromxy(22,13);printf("电话: %s",pp->tel);
    fromxy(22,15);printf("房间: %d",pp->room);
    fromxy(22,17);printf("房费: %d",pp->hotel);
    fromxy(22,19);printf("餐费: %d",pp->food);
    fromxy(18,21);printf("入住日期: %d-%d-%d",pp->start.year,pp->start.month,pp->start.day);
    fromxy(18,23);printf("到期时间: %d-%d-%d",pp->finish.year,pp->finish.month,pp->finish.day);
    fromxy(43,26);printf("修 改(r)");
   // fromxy(55,26);printf("删 除(d)");
    fromxy(67,26);printf("返 回(b)");
    clearColor();
}

void form_modification(void)  //修改信息界面
{
    setColor(0x70);
    graph_rectangle(70,8,17,17);
    graph_point(72,10,15);graph_point(72,12,15);
    graph_point(72,14,15);graph_point(72,16,15);
    graph_point(72,18,15);graph_point(72,20,15);
    graph_point(72,22,15);
    fromxy(76,9);printf("姓名:");
    fromxy(72,11);printf("身份证号:");
    fromxy(76,13);printf("电话:");
    fromxy(76,15);printf("房间:");
    fromxy(76,17);printf("房费:");
    fromxy(76,19);printf("餐费:");
    fromxy(72,21);printf("入住日期:     -  -");
    fromxy(72,23);printf("到期时间:     -  -");
    fromxy(55,26);printf("确认(Enter)");
    clearColor();
    fromxy(43,26);printf("        ");
    fromxy(67,26);printf("        ");
}

void form_delete(void)
{
    setColor(0x70);
    graph_rectangle(44,15,15,3);
    fromxy(54,16);printf("删除成功！！");
    clearColor();
}

void form_reserve(void)
{
    setColor(0x70);
    graph_rectangle(44,15,15,3);
    fromxy(54,16);printf("修改成功！！");
    clearColor();
}

void form_copyfile(void)    //备份界面
{
    clearScreen();
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(53,9);printf("备份中...");
    form_5s(62,9);
    clearColor();
}

void form_copysuccess(void)
{
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(53,9);printf("备份成功！");
    clearColor();
}

void form_cover(void)    //系统修复界面
{
    clearScreen();
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(49,9);printf("系统恢复中...");
    form_5s(62,9);
    clearColor();
}

void form_coversuccess(void)
{
    setColor(0x70);
    graph_rectangle(44,8,15,3);
    fromxy(53,9);printf("恢复成功！");
    clearColor();
}

void form_back(void)   //退订界面
{
    setColor(0x70);graph_rectangle(44,3,15,3);
    fromxy(50,4);printf("请输入姓名:");
    clearColor();
}

void form_backInformation(struct Client *p)  //退订信息显示
{
    setColor(0x70);
    graph_rectangle(44,11,15,9);
    graph_point(46,13,13);
    graph_point(46,15,13);
    graph_point(46,17,13);
    fromxy(46,12);printf("姓名:%s",p->name);
    fromxy(46,14);printf("房间:%d",p->room);
    fromxy(46,16);printf("房费:%d",p->hotel);
    fromxy(46,18);printf("餐费:%d",p->food);
    fromxy(48,21);printf("确认退订(y)");
    fromxy(62,21);printf("返 回(n)");
    clearColor();
}

void form_repay(struct Client *p)
{
    setColor(0x70);
    graph_rectangle(40,9,20,5);
    fromxy(50,10);printf("确认付款:共%d元!!!",p->hotel+p->food);
    clearColor();
    fromxy(52,12);printf("确认(y)");
    fromxy(62,12);printf("取消(n)");
}

void form_repaysuccess(void)
{
    setColor(0x70);
    graph_rectangle(40,9,20,5);
    fromxy(50,10);printf("     付款成功    ");
    fromxy(52,12);printf("按任意键返回");clearColor();
}

void form_repayfault(void)
{
    setColor(0x70);
    graph_rectangle(40,9,20,5);
    fromxy(50,10);printf("     付款失败    ");
    fromxy(52,12);printf("按任意键返回");clearColor();
}

void form_first_head(void)   //主界面
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
            fromxy(48,8);printf("欢迎光临xxx大酒店！");
           }
        else if(elapsed_time-b>1000)
            {
            setColor(0x2a);
            graph_and(42,6,31,4);b=elapsed_time;
            fromxy(48,8);printf("欢迎光临xxx大酒店！");
            }
        clearColor();
    }
}

void form_5s(int x,int y)   //5秒倒计时
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

void form_first_option(void)   //主界面动画
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
    fromxy(53,11);setColor(0xb0);printf("● 退  出 ");
    clearColor();
}

void form_first_option_3(void)
{
    setColor(0x3b);graph_Star(42,11,31,3);
    fromxy(53,12);setColor(0xb0);printf("● 退  出 ");
    clearColor();
}

void form_first_option_4(void)
{
    setColor(0x3b);graph_Star(42,11,31,4);
    setColor(0xb0);
    fromxy(53,11);printf("● 帮  助 ");
    fromxy(53,13);printf("● 退  出 ");
    clearColor();
}

void form_first_option_5(void)
{
    setColor(0x3b);graph_Star(42,11,31,5);
    setColor(0xb0);
    fromxy(53,12);printf("● 帮  助 ");
    fromxy(53,14);printf("● 退  出 ");
    clearColor();
}

void form_first_option_6(void)
{
    setColor(0x3b);graph_Star(42,11,31,6);
    setColor(0xb0);
    fromxy(53,11);printf("● 管理员 ");
    fromxy(53,13);printf("● 帮  助 ");
    fromxy(53,15);printf("● 退  出 ");
    clearColor();
}

void form_first_option_7(void)
{
    setColor(0x3b);graph_Star(42,11,31,7);
    setColor(0xb0);
    fromxy(53,12);printf("● 管理员 ");
    fromxy(53,14);printf("● 帮  助 ");
    fromxy(53,16);printf("● 退  出 ");
    clearColor();
}

void form_first_option_8(void)
{
    setColor(0x3b);graph_Star(42,11,31,8);
    setColor(0xb0);
    fromxy(53,11);printf("● 顾  客 ");
    fromxy(53,13);printf("● 管理员 ");
    fromxy(53,15);printf("● 帮  助 ");
    fromxy(53,17);printf("● 退  出 ");
    clearColor();
}

void form_first_option_9(void)
{
    setColor(0x3b);graph_Star(42,11,31,9);
    setColor(0xb0);
    fromxy(53,12);printf("● 顾  客 ");
    fromxy(53,14);printf("● 管理员 ");
    fromxy(53,16);printf("● 帮  助 ");
    fromxy(53,18);printf("● 退  出 ");
    clearColor();
}

void form_first_option_10(void)
{
    setColor(0x3b);graph_Star(42,11,31,10);
    setColor(0xb0);
    fromxy(53,13);printf("● 顾  客 ");
    fromxy(53,15);printf("● 管理员 ");
    fromxy(53,17);printf("● 帮  助 ");
    fromxy(53,19);printf("● 退  出 ");
    clearColor();
}

void form_safe(void)
{
    clearScreen();
    setColor(0x3b);
    graph_rectangle(44,10,15,3);
    fromxy(50,11);printf("请输入密码:");
    clearColor();
}

void form_remind(void)
{
    clearScreen();
    setColor(0x70);
    graph_rectangle(44,13,15,3);
    fromxy(50,14);printf("    号房间呼叫房管！");
    clearColor();
}

void form_password(void)    //管理员密码输入
{
    clearScreen();
    setColor(0x3b);graph_rectangle(44,8,15,3);
    fromxy(48,9);printf("请输入管理员密码:");
    clearColor();
}

