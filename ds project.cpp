#define ON 1
#define OFF 0
#include<stdio.h>
#include<graphics.h>
#include<string.h>
struct name
{
    int id;
    char sname[50];
    struct name*next;
};
struct name*head=NULL;
struct name*current=NULL;
void doCursor(int);
void newLine();
void getGrString(char *);
void userdetail();
void fareinfo();
void station();
void nearby();
int main()
{
    int i,j=0;
    int choice;
    char r_choice[50];
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
     settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
     for (i = 0; i <= 420; i = i + 10, j++)
   {
        outtextxy(165+i,120,"Delhi");
       outtextxy(165+i,140,"Metro");
       rectangle(150+i,110,250+i,210);
      rectangle(250+i,160,300+i,210);
      rectangle(100+i,160,150+i,210);
      rectangle(50+i,160,100+i,210);
      circle(70+i,220,10);
      circle(120+i,220,10);
      circle(175+i,220,10);
      circle(275+i,220,10);
      line(20,230,730,230);
      if(j==10)
      j=1;
      setcolor(j);

      delay(100);


        // break;

      clearviewport();
   }


    setcolor(WHITE);

    do{
            settextstyle(1,HORIZ_DIR,1);
    for(int i=20;i<90;i++)
    {
        outtextxy(i,100,"Welcome to Metro Information System");
        delay(10);
    }
    line(90,120,565,120);
    delay(500);
    settextstyle(6,HORIZ_DIR,1);
    outtextxy(60,150,"1.USER DETAIL");
    outtextxy(300,150,"2.FARE INFORMATION");
    outtextxy(60,200,"3.STATIONS");
    outtextxy(300,200,"4.LOCATION&STATION");
    outtextxy(60,250,"5.EXIT");
    outtextxy(90,400,"Please enter your option(1-4)");
    moveto(400,400);
    getGrString(r_choice);
    choice=atoi(r_choice);
    cleardevice();
    if(choice==1)
    {
        userdetail();
    }
    if(choice==2)
    {
        fareinfo();
        getch();
    }
    if(choice==3)
    {
        station();
        getch();
    }
    if(choice==4)
    {
        nearby();
        getch();
    }
    if(choice==5)
    {
        exit(0);
    }
    }while(choice==1||choice==2||choice==3||choice==4);
    closegraph();
    return 0;
}
void newLine()
  {
      moveto(0,gety()+textheight("A"));
  }
  void getGrString(char *inputString)
  {

     int stringIndex=0;
     int xVal[255];
     char inputChar, outString[2];
     int oldColor;
     outString[1]=0;
     xVal[0]=getx();
     do
     {
        doCursor(ON);
        inputChar=getch();
        doCursor(OFF);
        if (inputChar==0) getch();
        else
        {
            if (inputChar==8) {
                oldColor=getcolor();
                --stringIndex;
                if (stringIndex<0) stringIndex=0;
                moveto(xVal[stringIndex],gety());
                setcolor(getbkcolor());
                outString[0]=inputString[stringIndex];
                outtext(outString);
                moveto(xVal[stringIndex],gety());
                setcolor(oldColor);
            }
            else {
                inputString[stringIndex]=inputChar;
                outString[0]=inputChar;
                outtext(outString);
                ++stringIndex;
                xVal[stringIndex]=getx();
            }
         }
     } while(inputChar!=13 && inputChar!=10);
     inputString[stringIndex]=0;
  }
  void doCursor(int on) {
      int curX,oldColor;
      char uBarStr[2] = { '_',0 };
      if (!on) {
          oldColor=getcolor();
          setcolor(getbkcolor());
      }
      curX=getx();
      outtext(uBarStr);
      moveto(curX,gety());
      if (!on) setcolor(oldColor);
  }
  void userdetail()
  {
        FILE*fptr;
        int i,choice,card;
        char r_choice[50],name[50],sname[50],r_tel[50],card_no[50],bal[10];
        settextstyle(1,HORIZ_DIR,2);
        outtextxy(170,50,"USER INFORMATION");
        line(170,70,500,70);
        settextstyle(6,HORIZ_DIR,1);
        for(i=20;i<=90;i++)
        outtextxy(i,100,"1.ISSUE CARD");
        for(i=20;i<=90;i++)
        outtextxy(i,130,"2.SEARCH USER");
        for(i=20;i<=90;i++)
        outtextxy(i,160,"3.RECHARGE CARD");
        outtextxy(90,400,"Please enter your option(1-3)");
        moveto(400,400);
        getGrString(r_choice);
        choice=atoi(r_choice);
        cleardevice();
        if(choice==1)
        {   outtextxy(170,50,"ISSUING TRAVEL CARD");
            outtextxy(90,100,"NAME -");
            rectangle(200,90,500,120);
            moveto(210,95);
            getGrString(name);
            outtextxy(90,150,"TEL: -");
            rectangle(200,140,500,170);
            moveto(210,145);
            getGrString(r_tel);
            outtextxy(80,200,"CARD.NO-");
            rectangle(200,190,500,220);
            moveto(210,195);
            getGrString(card_no);
            outtextxy(200,400,"Press Enter to register");
            getch();
            fptr= fopen("mdetail.txt","a");
            fprintf(fptr,"%s\n%s\n%s\n%d\n",name,r_tel,card_no,100);
            cleardevice();
            outtextxy(100,200,"INFORMATION SUCCESSFULLY SAVED!!");
            getch();
            fclose(fptr);
        }
        if(choice==2)
        {
            char phone[50];int card,r_card;
            outtextxy(200,50,"SEARCHING USER");
            outtextxy(200,100,"Enter Card Number ");
            rectangle(215,130,380,160);
            moveto(225,135);
            getGrString(card_no);
            r_card=atoi(card_no);
            outtextxy(80,170,"Name");
            outtextxy(240,170,"Phone");
            outtextxy(380,170,"Current Balance");
            fptr=fopen("mdetail.txt","r");
            while(!feof(fptr))
            {
                fscanf(fptr,"%s%s%s%d%s",name,sname,phone,&card,bal);
                if(card==r_card)
                {
                outtextxy(80,200,name);
                outtextxy(240,200,phone);
                outtextxy(420,200,bal);
                card=0;
                 fclose(fptr);break;
                }
            }if(card!=0)
                outtextxy(170,200,"No such user registered!!");
            getch();
        }
        if(choice==3)
        {
            char phone[50],amnt[10];int card,r_card,r_amnt,r_bal;
            outtextxy(180,50,"RECHARGE SCREEN");
            outtextxy(200,100,"Enter Card Number ");
            rectangle(215,130,380,160);
            moveto(225,135);
            getGrString(card_no);
            r_card=atoi(card_no);
            outtextxy(180,180,"Enter Amount In Rupees");
            rectangle(215,210,380,240);
            moveto(225,215);
            getGrString(amnt);
            r_amnt=atoi(amnt);
            fptr=fopen("mdetail.txt","r+");
            while(!feof(fptr))
            {
                fscanf(fptr,"%s%s%s%d%s",name,sname,phone,&card,bal);
                if(card==r_card)
                {
                    r_bal=atoi(bal);
                    r_bal+=r_amnt;
                    card=0;
                    sprintf(bal,"%d",r_bal);
                    fseek(fptr,-strlen(bal),SEEK_CUR);
                    fprintf(fptr,"%s",bal);
                    break;
                }
            }if(card!=0)
                {outtextxy(170,300,"No such user registered!!");
                getch();
                fclose(fptr);}
             else{
                 outtextxy(95,300,name);
                 outtextxy(180,300,",Your current balance is:");
                 outtextxy(430,300,bal);
                 getch();
                 fclose(fptr);
                }
        }
        cleardevice();
  }
 void fareinfo()
  {
        FILE*fptr;
        fptr=fopen("mstation.txt","r+");
        char sname[50],fstation[50],sfare[5];
        int count=1,diff,fare;
        while( fgets(sname,50,fptr)!=NULL)
        {
            struct name*newnode=(struct name*)malloc(sizeof(struct name));
            newnode->next=NULL;
            newnode->id=count;
            strcpy(newnode->sname,sname);
            if(head==NULL)
            {
                head=newnode;
                current=newnode;
            }
            else
            {
                current->next=newnode;
                current=newnode;
            }
            count++;
        }
        struct name*ptr=head;
        outtextxy(200,0,"FROM STATION");
        outtextxy(90,gety()+textheight("A"),"Please select valid station number from list: ");
        line(3,gety()+3*textheight("A"),3,gety()+22*textheight("A"));
        line(250,gety()+3*textheight("A"),250,gety()+22*textheight("A"));
        int i=3,f_no,t_no;char id[5],fno[5],tno[5];
        while(ptr!=NULL)
        {
            if(i<=21){
            sprintf(id,"%d",ptr->id);
            outtextxy(7,gety()+i*textheight("A"),id);
            outtextxy(getx()+2*textheight(id),gety()+i*textheight("A"),ptr->sname);
            i+=2;
            ptr=ptr->next;}
            if(i>21&&i<=41){
                sprintf(id,"%d",ptr->id);
            outtextxy(255,gety()+(i-20)*textheight("A"),id);
            outtextxy(255+getx()+2*textheight(id),gety()+(i-20)*textheight("A"),ptr->sname);
            i+=2;
            ptr=ptr->next;
            }
            if(i>41)
                break;
        }
        outtextxy(90,450,"Please enter valid station number: ");
        moveto(450,450);
        getGrString(fno);
        f_no=atoi(fno);
        cleardevice();
        outtextxy(200,0,"TO STATION");
        outtextxy(90,gety()+textheight("A"),"Please select valid station number from list");
        line(3,gety()+3*textheight("A"),3,gety()+22*textheight("A"));
        line(250,gety()+3*textheight("A"),250,gety()+22*textheight("A"));
        i=3;
        ptr=head;
        while(ptr!=NULL)
        {
            if(i<=21){
            sprintf(id,"%d",ptr->id);
            outtextxy(7,gety()+i*textheight("A"),id);
            outtextxy(getx()+2*textheight(id),gety()+i*textheight("A"),ptr->sname);
            i+=2;
            ptr=ptr->next;}
            if(i>21&&i<=41){
                sprintf(id,"%d",ptr->id);
            outtextxy(255,gety()+(i-20)*textheight("A"),id);
            outtextxy(255+getx()+2*textheight(id),gety()+(i-20)*textheight("A"),ptr->sname);
            i+=2;
            ptr=ptr->next;
            }
            if(i>41)
                break;
        }
        outtextxy(90,450,"Please enter valid station number:");
        moveto(450,450);
        getGrString(tno);
        t_no=atoi(tno);
        fclose(fptr);
        cleardevice();
        if(t_no>20||t_no<1||f_no>20||f_no<1)
            outtextxy(100,200,"INVALID STATION SELECTED!!");
        else{
        diff=abs(t_no-f_no);
        outtextxy(200,50,"FARE INFORMATION:");
        outtextxy(80,120,"FROM :");
        outtextxy(240,120,"TO:");
        outtextxy(400,120,"FARE:");
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->id==f_no)
                outtextxy(80,150,ptr->sname);
            if(ptr->id==t_no)
                outtextxy(240,150,ptr->sname);
            ptr=ptr->next;
        }
        if(diff==1) fare=10;
        if(diff>1&&diff<=5) fare=20;
        if(diff>5&&diff<=12)fare=30;
        if(diff>12&&diff<=18)fare=40;
        if(diff>18&&diff<=20)fare=50;
        sprintf(sfare,"%d",fare);
        outtextxy(400,150,sfare);}
        getch();
        cleardevice();
  }
  void station()
  {
        FILE*fptr;
        fptr=fopen("mstation.txt","r+");
        char sname[50];
        int count=1;
        int i=3;char id[5];
        while( fgets(sname,50,fptr)!=NULL)
        {
            struct name*newnode=(struct name*)malloc(sizeof(struct name));
            newnode->next=NULL;
            newnode->id=count;
            strcpy(newnode->sname,sname);
            if(head==NULL)
            {
                head=newnode;
                current=newnode;
            }
            else
            {
                current->next=newnode;
                current=newnode;
            }
            count++;
        }
        struct name*ptr=head;
        outtextxy(200,0,"**STATIONS INFO**");
        line(3,gety()+3*textheight("A"),3,gety()+22*textheight("A"));
        line(250,gety()+3*textheight("A"),250,gety()+22*textheight("A"));
        i=3;
        while(ptr!=NULL)
        {
            if(i<=21){
            sprintf(id,"%d",ptr->id);
            outtextxy(7,gety()+i*textheight("A"),id);
            outtextxy(getx()+2*textheight(id),gety()+i*textheight("A"),ptr->sname);
            i+=2;
            ptr=ptr->next;}
            if(i>21&&i<=41){
                sprintf(id,"%d",ptr->id);
            outtextxy(255,gety()+(i-20)*textheight("A"),id);
            outtextxy(255+getx()+2*textheight(id),gety()+(i-20)*textheight("A"),ptr->sname);
            i+=2;
            ptr=ptr->next;
            }
            if(i>41)
                break;
        }
        getch();
        cleardevice();
  }
  void nearby()
  {
        FILE*fptr;
        fptr=fopen("nearby.txt","r+");
        char sname[50];
        int i=3;
        outtextxy(120,0,"LOCATIONS NEAR STATIONS:");
        outtextxy(20,30,"LOCATIONS:");
        outtextxy(300,30,"STATIONS:");
        while(fgets(sname,50,fptr)!=NULL)
        {
            outtextxy(7,gety()+i*textheight("A"),sname);
            newLine();
            i++;
        }
        getch();
        cleardevice();
  }
