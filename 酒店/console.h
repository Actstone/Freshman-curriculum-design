#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include<time.h>

//结构体
struct tm *nowclock; //时间变量
struct Print //输入框
{
    int x,y;
    char id[50];
    bool set;
    int num;
};
struct Print *print[5];

struct State //选项
{
    int x, y;
    unsigned short color1, color2;
    char *text;
    bool selected;
};
typedef struct State * state;

struct Restroom  //剩余房间
{
    int one[16];
    int two[16];
    int three[16];
    int four[16];
};

struct REST
{
    int room;
    int ty;
    struct REST *next;
};
struct REST *rest_head;

struct Date  //日期
{
    int year;
    int month;
    int day;
};

struct Rooming   //已住房间
{
    int room;
    struct Date finish;
    struct Rooming *next;
};
struct Rooming *rooming_head;

struct Client   //客户信息
{
    char name[50];
    char card[50];
    char tel[50];
    int room;
    int hotel;
    int food;
    struct Date start;
    struct Date finish;
    struct Client *next;
};
struct Client *Client_head;

//控制台 console
void initConsole(void);
void fromxy(int x, int y);
void setColor(unsigned short);
void clearColor(void);
void clearScreen(void);
void destroyConsole(void);
void hideCursor(void);
void showCursor(void);
//void Free(struct client *p);
void Scanf_s(int x,int y,char *s);
void Scanf_d(int x,int y,int *d);
//图形 graph
void graph_rectangle(int x,int y,int w,int h);
void graph_Star(int x,int y,int w,int h);
void graph_and(int x,int y,int w,int h);
void graph_Sline(int x,int y,int lengh);
void graph_Hline(int x,int y,int lengh);
void graph_1(int x,int y);
void graph_2(int x,int y);
void graph_3(int x,int y);
void graph_4(int x,int y);
void graph_5(int x,int y);
void graph_6(int x,int y);
void graph_7(int x,int y);
void graph_8(int x,int y);
void graph_9(int x,int y);
void graph_10(int x,int y);
void graph_arrow(void);
void graph_point(int x,int y,int lenth);
void prin(struct Rooming *y);

// 表格 form
void form_menu(void);
void form_foodpay(int M);
void form_roompay(int price);
void form_order_success(void);
void form_room(void);
void form_reserve(void);
void form_checkin(void);
void form_checkSuccess(void);
int form_call(void);
void form_callsuccess(void);
void form_inname(void);
void form_incard(void);
void form_inroom(void);
void form_findresult(struct Client *pp);
void form_modification(void);
void form_delete(void);
void form_copyfile(void);
void form_5s(int x,int y);
void form_copysuccess(void);
void form_cover(void);
void form_coversuccess(void);
void form_back(void);
void form_backInformation(struct Client *p);
void form_repay(struct Client *p);
void form_repaysuccess(void);
void form_repayfault(void);
void form_first_head(void);
void form_first_option(void);
void form_first_option_1(void);
void form_first_option_2(void);
void form_first_option_3(void);
void form_first_option_4(void);
void form_first_option_5(void);
void form_first_option_6(void);
void form_first_option_7(void);
void form_first_option_8(void);
void form_first_option_9(void);
void form_first_option_10(void);
void form_safe(void);
void form_password(void);
void form_remind(void);
//语句 sentence
void sentence_1(void);
void sentence_2(void);
void sentence_3(void);
void sentence_4(void);
void sentence_5(void);
void sentence_6(void);
void sentence_7(void);
void sentence_8(void);
void sentence_9(void);
void sentence_10(void);
void sentence_12(void);
void sentence_14(void);
//特殊 special
state special_init(int x,int y,unsigned short color1,unsigned short color2,char *text);
void special_setSelect(state a);
void special_removeSelect(state a);
int special_getKey(void);
void special_printfstate(state b);
void special_first_botton(void);
void special_second_botton(void);
void special_third_botton(void);
void special_find_botton(void);
void special_menu(void);
void special_flycome(int x,int y,unsigned short color,int Start,int Finish,char *text);
void special_flygo(int x,int y,unsigned short color,int lenth,int Finish,char *text);
//数据 data
void data_call_write(int r);
void data_restroom(void);
void data_call_back(void);
void data_deleted(struct Client *now);
struct Client *data_client_read(void);
void data_password(void);
void data_checkin(void);
void data_PPrintf(struct Print *pp);
struct Print * data_init(int x,int y);
void data_client_write(struct Client *head);
struct Client *data_find_name(struct Client *head);
struct Client *data_find_card(struct Client *head);
struct Client *data_find_room(struct Client *head);
struct Client *data_find_address(struct Client *head,struct Client *q);
void data_continuein(char *name,char *card,char *tel,char *room,int hotel,int food,int iny,int inm,int ind,int outy,int outm,int outd);
void data_gettime(void);
struct Rooming *data_rooming_read(void);
struct REST *data_restroom_read(void);
void data_fuzhi(char *p,char *q);
void data_restroom_write(struct REST *head);
void data_deleted_restroom(struct REST *now);
struct REST *data_find_restroom(struct REST *head,int n);
void data_inrooming(int room,int year,int mon,int day);
struct Rooming *data_find_rooming(struct Rooming *head,int n);
void data_rooming_write(struct Rooming *head);
void data_reservein(struct Client *v);
void data_deleted_rooming(struct Rooming *now);

#endif // DF_H_INCLUDED
