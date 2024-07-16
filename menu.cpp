#include<menu.hpp>
#include<iostream>
#include<graphics.h>
#include <vector>
#include <fstream>

using namespace std;

int xs1=20, xs2=435;

//��������� ����
void draw_menu(){
   setcolor(BLACK);
   setbkcolor(NO_COLOR);
   setfillstyle(1,COLOR(250, 128, 114));
   bar(0 , 0, wx, wy);
   setfillstyle(1,WHITE);
   bar(xs1, 60, xs2, 80);
   rectangle(xs1, 60, xs2, 80);
   for(int i=1; i<5; ++i){
      int k=i*60;
      if(i==1){
         bar(xs1, 60+k, xs2/2-10, 80+k);
         rectangle(xs1, 60+k, xs2/2-10, 80+k);
         bar(xs2/2+10, 60+k, xs2, 80+k);
         rectangle(xs2/2+10, 60+k, xs2, 80+k);
      }
      else{
      bar(xs1, 60+k, xs2/2-80, 80+k);
      rectangle(xs1, 60+k, xs2/2-80, 80+k);
      }
   }
   outtextxy(xs1, 45, "��� �����");
   outtextxy(xs1, 105, "������");
   outtextxy(xs2/2+10, 105, "������");
   outtextxy(xs1+5, 180, "�������������");
   outtextxy(xs1+5, 240, "��������");
   outtextxy(xs1+5, 300, "� ���������");
}

//�������� ������
void prov_pole(int x, int y){
   if(x>=xs1 && x<=xs2 && y>=240 && y<=260){use_but(2); return;}
   if(x>=xs1 && x<=xs2 && y>=180 && y<=200){use_but(1); return;}
   if(x>=xs1 && x<=xs2 && y>=60 && y<=80){filename=input_word(xs1, 60, xs2, 80, 0); return;}
   if(x>=xs1 && x<=xs2/2-10 && y>=120 && y<=140){dx=stoi(input_word(xs1, 120, xs2/2-10, 140, 1)); return;}
   if(x>=xs2/2+10 && x<=xs2 && y>=120 && y<=140){dy=stoi(input_word(xs2/2+10, 120, xs2, 140, 1)); return;}
   if(x>=xs1 && x<=xs2/2 && y>=300 && y<=320){about_programm(); return;}
   return;
}

//������������� ������
void use_but(int i){
   switch(i){
      case 1: /*generate();*/break;
      case 2: clear_all(); break;
   }
   return;
}

void draw_cursor(int x, int y, int c) { // ��������� ��������� �������
   setcolor(c);
   line(x, y, x, y+textheight("A")-1);
}

//��������� ����� ����� ��� �������� �����
string input_word(const int startX, const int startY, const int endX, const int endY, const int i){
   setbkcolor(NO_COLOR);
   setfillstyle(1,WHITE);
   setcolor(BLACK);
   int f=1;// ����
   int ch;
   int cur=0;
   string word;
   int len=word.size();
   int x1=startX, y1 = startY;
   while(1){
      draw_cursor(startX+textwidth(word.c_str())+7, startY+2, cur<10?BLACK:WHITE);
      cur=(cur+1)%20;
      if(!kbhit()) delay(50);
         else {
            f=1;
            if(!i){if(word.size()>50) f=0;}
            else if(word.size()>8) f=0;
            ch = getch();
            if(ch==KEY_ENTER) break;
            if(ch==KEY_ESC){
               if(!i) word="Noname.txt";
               else word='0';
               break;
            }
            else if (ch == KEY_BACKSPACE && len>0) word.erase(--len, 1);
            else if (ch>' ' && ch<='z' && f && ch!='*'){
               if(!i){word+=ch; ++len;}
               else if(ch>48 && ch<=57){word+=ch; ++len;}
            }
            // ����� �������� �����
            bar(startX, startY, endX, endY);
            rectangle(startX, startY, endX, endY); 
            setcolor(BLACK);
            outtextxy(x1+5, y1+1, word.c_str());
         }
   }
   draw_cursor(startX+textwidth(word.c_str())+7, startY+2, WHITE);
   return word;
}

//�������� ��������
void clear_all(){
   draw_menu();
   dx=0, dy=0;
   filename="Noname.txt";
}

void about_programm(){
   return;
}