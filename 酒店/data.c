#include<stdio.h>
#include"console.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>

void data_call_write(int r)    //呼叫房间写入文件
{
    FILE *fp;
    fp=fopen("file//call.txt","a");
    fprintf(fp,"%d\n",r);
    fclose(fp);
}

void data_restroom(void)       //剩余房间显示
{
    FILE *fp;
    struct Restroom restroom;
    int i,room,type,a=0,b=0,c=0,d=0;
    fp=fopen("file//restroom.txt","r");
    fscanf(fp,"%d%d",&room,&type);
    while(room!=0)
    {
        if(type==1) {restroom.one[a]=room;a++;}
        else if(type==2) {restroom.two[b]=room;b++;}
        else if(type==3) {restroom.three[c]=room;c++;}
        else if(type==4) {restroom.four[d]=room;d++;}
        fscanf(fp,"%d%d",&room,&type);
    }
    restroom.one[a]=0;
    restroom.two[b]=0;
    restroom.three[c]=0;
    restroom.four[d]=0;
    fromxy(31,5);
    for(i=0;restroom.one[i]!=0;i++)
    {
        printf("%d ",restroom.one[i]);
    }
    fromxy(31,7);
    for(i=0;restroom.two[i]!=0;i++)
    {
        printf("%d ",restroom.two[i]);
    }
    fromxy(31,9);
    for(i=0;restroom.three[i]!=0;i++)
    {
        printf("%d ",restroom.three[i]);
    }
    fromxy(31,11);
    for(i=0;restroom.four[i]!=0;i++)
    {
        printf("%d ",restroom.four[i]);
    }
    fclose(fp);
}

void data_call_back(void)
{
    FILE *fp;
    int call;
    fp=fopen("file//call.txt","r");
    if(fscanf(fp,"%d",&call)!=EOF)
    {
        do
        {
            printf("%d",call);
        }
        while(fscanf(fp,"%d",&call)!=EOF);
    }
    fp=fopen("file//call.txt","w");
    fclose(fp);
}

struct Client *data_client_read(void)    //读取客户信息文件
{
    FILE *fp;
    struct Client *head;
    struct Client *p1,*p2;
    int n=0;
    fp=fopen("file\\client.txt","r");
    if(fp==NULL)
    {
        printf("ddd");exit(0);
    }
    p1=p2=(struct Client *)malloc(sizeof(struct Client));
    fscanf(fp,"%s%s%s%d%d%d%d%d%d%d%d%d",p1->name,p1->card,p1->tel,&p1->room,
           &p1->hotel,&p1->food,&p1->start.year,&p1->start.month,
           &p1->start.day,&p1->finish.year,&p1->finish.month,
           &p1->finish.day);
    head=NULL;
    do
    {
        n=n+1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Client *)malloc(sizeof(struct Client));
    }while(fscanf(fp,"%s%s%s%d%d%d%d%d%d%d%d%d",p1->name,p1->tel,p1->card,&p1->room,
           &p1->hotel,&p1->food,&p1->start.year,&p1->start.month,
           &p1->start.day,&p1->finish.year,&p1->finish.month,
           &p1->finish.day)!=EOF);
    p2->next=NULL;
    fclose(fp);
    return(head);
}

struct REST *data_restroom_read(void)    //剩余房间读入
{
    FILE *fp;
    struct REST *head;
    struct REST *p1,*p2;
    int n=0;
    fp=fopen("file\\restroom.txt","r");
    if(fp==NULL)
    {
        printf("ddd");exit(0);
    }
    p1=p2=(struct REST *)malloc(sizeof(struct REST));
    fscanf(fp,"%d%d",&p1->room,&p1->ty);
    head=NULL;
    do
    {
        n=n+1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct REST *)malloc(sizeof(struct REST));
    }while(fscanf(fp,"%d%d",&p1->room,&p1->ty)!=EOF);
    p2->next=NULL;
    fclose(fp);
    return(head);
}

struct Rooming *data_rooming_read(void)  //已住房间读入
{
    FILE *fp;
    struct Rooming *head;
    struct Rooming *p1,*p2;
    int n=0;
    fp=fopen("file\\rooming.txt","r");
    if(fp==NULL)
    {
        printf("ddd");exit(0);
    }
    p1=p2=(struct Rooming *)malloc(sizeof(struct Rooming));
    fscanf(fp,"%d%d%d%d",&p1->room,&p1->finish.year,&p1->finish.month,&p1->finish.day);
    head=NULL;
    do
    {
        n=n+1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Rooming *)malloc(sizeof(struct Rooming));
    }while(fscanf(fp,"%d%d%d%d",&p1->room,&p1->finish.year,&p1->finish.month,&p1->finish.day)!=EOF);
    p2->next=NULL;
    fclose(fp);
    return(head);
}

struct Client *data_find_name(struct Client *head)   //按名字查找
{
    char n[20];
    struct Client *p;
    p=head;
    fromxy(62,4);
    setColor(0x70);scanf("%s",n);
    while(p!=NULL&&strcmp(n,p->name)!=0)
    {
        p=p->next;
    }
    return(p);
}

struct Client *data_find_card(struct Client *head)
{
    char n[19];
    struct Client *p;
    p=head;
    fromxy(60,4);
    setColor(0x70);scanf("%s",n);
    n[18]='\0';
    while(p!=NULL&&strcmp(n,p->card)!=0)
    {
        p=p->next;
    }
    return(p);
}

struct Client *data_find_room(struct Client *head)
{
    int n;
    struct Client *p;
    p=head;
    setColor(0x70);
    scanf("%d",&n);
    while(p!=NULL&&n!=p->room)
    {
        p=p->next;
    }
    return(p);
}

void data_deleted(struct Client *now)    //删除指定客户信息
{
    struct Client * h = Client_head;
    if ( h == now) {
        h = now -> next;
        free(now);
        Client_head = h;
    }
    else{
    while( h -> next != NULL) {
        if (h -> next == now) {
            h -> next = now -> next;
            free(now);
            break;
        }
        h = h -> next;
    }
    }
}

void data_client_write(struct Client *head)    //客户信息写入
{
    struct Client *p;
    FILE *fp;
    fp=fopen("file//client.txt","w");
    p=head;
    if(head!=NULL)
        do
        {
            fprintf(fp,"%s %s %s %d %d %d %d %d %d %d %d %d\n",p->name,p->card,
                    p->tel,p->room,p->hotel,p->food,p->start.year,p->start.month,
                    p->start.day,p->finish.year,p->finish.month,p->finish.day);
            p=p->next;
        }while(p!=NULL);
    fclose(fp);
}

void data_password(void)   //管理员密码判断
{
    char real_password[8]={"123456"},password[8];
    int i=0,t=0;
    password[6]='\0';
    showCursor();
    setColor(0x3b);
    while(1){
    while(i<6)
    {

        int e=special_getKey();
        if(e == 8)
        {
            if(t!=0)
            {
                printf("\b \b");
                i--;t--;
            }
        }
        else if(isalpha(e)||isdigit(e))
        {
            password[i]=e;i++;
            printf("*");t++;
        }
        else
            ;

    }
    clearColor();
    if(strcmp(password,real_password)==0)
    {
        clearScreen();
        break;
    }
    else
            {
                fromxy(54,12);
                printf("ÃÜÂë´íÎó");
                setColor(0x70);
                fromxy(65,9);printf("      ");
                fromxy(65,9);i=0;t=0;
                continue;
            }
    }

    hideCursor();

}

struct Print * data_init(int x,int y)   //输入框输出
{
    struct Print * answer=(struct Print *)malloc(sizeof(struct Print));
    answer->x=x;
    answer->y=y;
    answer->set=false;
    answer->num=0;
};

void data_PPrintf(struct Print *pp)   //按指定位置输出
{
    if(pp->set==true)
        fromxy(pp->x,pp->y);
}

void data_checkin(void)    //登记
{
    showCursor();
    int i,Focu=0;
    struct Print *print[5];
    print[0]=data_init(45,16);
    print[1]=data_init(45,18);
    print[2]=data_init(45,20);
    print[3]=data_init(45,22);
    print[4]=data_init(45,24);
    print[0]->set=true;
    while(1)
    {
        for(i=0;i<5;i++)
            data_PPrintf(print[i]);
        int chi=special_getKey();
        if (chi == -80)
        {
          if (Focu == 4);
          else
          {
              print[Focu]->set=false;
              Focu++;
              print[Focu]->set=true;
          }
        }
        else if(chi==-72)
        {
          if(Focu==0);
          else
          {
              print[Focu]->set=false;
              Focu--;
              print[Focu]->set=true;
          }
        }
        else if(chi == 8)
        {
            if(print[Focu]->num!=0)
            {
                printf("\b \b");
                print[Focu]->num--;
                print[Focu]->x--;
            }
        }
        else if(isalpha(chi)||isdigit(chi))
        {
            printf("%c",chi);
            print[Focu]->id[print[Focu]->num]=chi;
            print[Focu]->num++;
            print[Focu]->x++;
        }
        else if(chi == 13)
        {
            if(Focu == 4)
            {
                hideCursor();
                print[0]->id[print[0]->num]='\0';
                print[1]->id[print[1]->num]='\0';
                print[2]->id[print[2]->num]='\0';
                print[3]->id[print[3]->num]='\0';
                print[4]->id[print[4]->num]='\0';
                data_gettime();
                int hfee=(int)print[3]->id[0]-48;
                int dayy=atoi(print[4]->id);
                if(hfee==1){hfee=dayy*600;}
                else if(hfee==2){hfee=dayy*300;}
                else if(hfee==3){hfee=dayy*200;}
                else if(hfee==4){hfee=dayy*100;}
                int DAY,YEAR=nowclock->tm_year+1900,MON=nowclock->tm_mon+1;
                DAY=nowclock->tm_mday+dayy;
                while(DAY>30||MON>12)
                {
                    if(DAY>30){DAY-=30;MON+=1;}
                    if(MON>12){MON-=12;YEAR+=1;}
                }
                data_continuein(print[0]->id,print[2]->id,print[1]->id,print[3]->id,
                                hfee,0,nowclock->tm_year+1900,nowclock->tm_mon+1,nowclock->tm_mday,
                                YEAR,MON,DAY);
                rest_head=data_restroom_read();
                data_deleted_restroom(data_find_restroom(rest_head,atoi(print[3]->id)));
                data_restroom_write(rest_head);
                data_inrooming(atoi(print[3]->id),YEAR,MON,DAY);
                break;
            }
            else
            {
              print[Focu]->set=false;
              Focu++;
              print[Focu]->set=true;
            }
        }
    }
}

void data_continuein(char *name,char *tel,char *card,char *room,int hotel,int food,int iny,int inm,int ind,int outy,int outm,int outd)//登记信息续写入文件
{
    FILE *fp;
    fp=fopen("file//client.txt","a");
    fprintf(fp,"%s %s %s %s %d %d %d %d %d %d %d %d\n",name,tel,card,room,hotel,food,iny,inm,ind,outy,outm,outd);
    fclose(fp);
}

void data_gettime(void)   //获取当前时间
{
    time_t timer;
    timer=time(NULL);
    nowclock=localtime(&timer);
}

struct REST *data_find_restroom(struct REST *head,int n)   //查找同一类的剩余房间
{
    struct REST *p;
    p=head;
    while(p!=NULL&&n!=p->room)
    {
        p=p->next;
    }
    return(p);
}

struct Rooming *data_find_rooming(struct Rooming *head,int n)
{
    struct Rooming *p;
    p=head;
    while(p!=NULL&&n!=p->room)
    {
        p=p->next;
    }
    return(p);
}

void data_inrooming(int room,int year,int mon,int day)  //写入rooming文件
{
    FILE *fp;
    fp=fopen("file//rooming.txt","a");
    fprintf(fp,"%d %d %d %d \n",room,year,mon,day);
    fclose(fp);
}

void data_deleted_restroom(struct REST *now)   //删除指定剩余房间
{
    struct REST * h = rest_head;
    if ( h == now) {
        h = now -> next;
        free(now);
        rest_head = h;
    }
    else{
    while( h -> next != NULL) {
        if (h -> next == now) {
            h -> next = now -> next;
            free(now);
            break;
        }
        h = h -> next;
    }
    }
}

void data_deleted_rooming(struct Rooming *now)
{
    struct Rooming * h = rooming_head;
    if ( h == now) {
        h = now -> next;
        free(now);
        rooming_head = h;
    }
    else{
    while( h -> next != NULL) {
        if (h -> next == now) {
            h -> next = now -> next;
            free(now);
            break;
        }
        h = h -> next;
    }
    }
}

void data_restroom_write(struct REST *head)    //写入剩余房间
{
    struct REST *p;
    FILE *fp;
    fp=fopen("file//restroom.txt","w");
    p=head;
    if(head!=NULL)
        do
        {
            fprintf(fp,"%d %d\n",p->room,p->ty);
            p=p->next;
        }while(p!=NULL);
    fclose(fp);
}

void data_rooming_write(struct Rooming *head)
{
    struct Rooming *p;
    FILE *fp;
    fp=fopen("file//rooming.txt","w");
    p=head;
    if(head!=NULL)
        do
        {
            fprintf(fp,"%d %d %d %d \n",p->room,p->finish.year,p->finish.month,p->finish.day);
            p=p->next;
        }while(p!=NULL);
    fclose(fp);
}

void data_fuzhi(char *p,char *q)   //复制字符串
{
    int i;
    for(i=0;i<21;i++)
        p[i]=q[i];
}

void data_reservein(struct Client *v)    //修改客户数据
{
    showCursor();
    int i,Focu=0;setColor(0x70);
    struct Print *print[12];
    print[0]=data_init(82,9);
    print[1]=data_init(82,11);
    print[2]=data_init(82,13);
    print[3]=data_init(82,15);
    print[4]=data_init(82,17);
    print[5]=data_init(82,19);
    print[6]=data_init(82,21);
    print[7]=data_init(87,21);
    print[8]=data_init(90,21);
    print[9]=data_init(82,23);
    print[10]=data_init(87,23);
    print[11]=data_init(90,23);
    print[0]->set=true;
    while(1)
    {
        for(i=0;i<12;i++)
            data_PPrintf(print[i]);
        int chi=special_getKey();
        if (chi == -80)
        {
          if (Focu == 11);
          else
          {
              print[Focu]->set=false;
              Focu++;
              print[Focu]->set=true;
          }
        }
        else if(chi==-72)
        {
          if(Focu==0);
          else
          {
              print[Focu]->set=false;
              Focu--;
              print[Focu]->set=true;
          }
        }
        else if(chi == 8)
        {
            if(print[Focu]->num!=0)
            {
                printf("\b \b");
                print[Focu]->num--;
                print[Focu]->x--;
            }
        }
        else if(isalpha(chi)||isdigit(chi))
        {
            printf("%c",chi);
            print[Focu]->id[print[Focu]->num]=chi;
            print[Focu]->num++;
            print[Focu]->x++;
        }
        else if(chi == 13)
        {
            if(Focu == 11)
            {
                hideCursor();
                print[0]->id[print[0]->num]='\0';
                print[1]->id[print[1]->num]='\0';
                print[2]->id[print[2]->num]='\0';
                print[3]->id[print[3]->num]='\0';
                print[4]->id[print[4]->num]='\0';
                print[5]->id[print[5]->num]='\0';
                print[6]->id[print[6]->num]='\0';
                print[7]->id[print[7]->num]='\0';
                print[8]->id[print[8]->num]='\0';
                print[9]->id[print[9]->num]='\0';
                print[10]->id[print[10]->num]='\0';
                print[11]->id[print[11]->num]='\0';
                rooming_head=data_rooming_read();
                struct Rooming *qqq=data_find_rooming(rooming_head,v->room);
                qqq->room=atoi(print[3]->id);
                qqq->finish.year=atoi(print[9]->id);
                qqq->finish.month=atoi(print[10]->id);
                qqq->finish.day=atoi(print[11]->id);
                data_rooming_write(rooming_head);
                rest_head=data_restroom_read();
                struct REST *ppp=data_find_restroom(rest_head,atoi(print[3]->id));
                ppp->room=v->room;
                ppp->ty=v->room/100;
                data_restroom_write(rest_head);
                data_fuzhi(v->name,print[0]->id);
                data_fuzhi(v->tel,print[1]->id);
                data_fuzhi(v->card,print[2]->id);
                v->room=atoi(print[3]->id);v->hotel=atoi(print[4]->id);v->food=atoi(print[5]->id);
                v->start.year=atoi(print[6]->id);v->start.month=atoi(print[7]->id);
                v->start.day=atoi(print[8]->id);v->finish.year=atoi(print[9]->id);
                v->finish.month=atoi(print[10]->id);v->finish.day=atoi(print[11]->id);
                data_client_write(Client_head);break;
            }
            else
            {
              print[Focu]->set=false;
              Focu++;
              print[Focu]->set=true;
            }
        }
    }
}

void prin(struct Rooming *y)
{
    struct Rooming *yy=y;
    while(yy!=NULL)
    {
        printf("%d ",yy->room);
        yy=yy->next;
    }
}
