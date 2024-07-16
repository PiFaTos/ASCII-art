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
   setfillstyle(1,COLOR(164, 245, 180));
   bar(0 , 0, wx, wy);
   setfillstyle(1,WHITE);
   for(int i=0; i<5; ++i){
      int k=i*60;
      if(i==1){
         bar(xs1, 60+k, xs2/2, 80+k);
         rectangle(xs1, 60+k, xs2/2, 80+k);
         bar(xs2-40, 60+k, xs2, 80+k);
         rectangle(xs2-40, 60+k, xs2, 80+k);
      }
      else{
      bar(xs1, 60+i*40, xs2, 80+i*40);
      rectangle(xs1, 60+i*40, xs2, 80+i*40);
      }
   }
   outtextxy(xs1, 40, "��� �����");
   outtextxy(xs1, 85, "������");
   outtextxy(xs2/2+10, 85, "������");
   outtextxy(xs1+5, 145, "�������������");
   outtextxy(xs1+5, 185, "��������");
   outtextxy(xs1+5, 225, "� ���������");
}

//�������� ������
void prov_pole(int x, int y){
   if(x>=xs1 && x<=xs2 && y>=140 && y<=160){use_but(1); return;}
   if(x>=xs1 && x<=xs2 && y>=180 && y<=200){use_but(2); return;}
   if(x>=xs1 && x<=xs2 && y>=60 && y<=80){filename=input_word(xs1, 60, xs2, 80); return;}
   if(x>=xs1 && x<=xs2/2 && y>=110 && y<=130){dx=stoi(input_word(xs1, 110, xs2, 130)); return;}
   if(x>=xs2-40 && x<=xs2 && y>=110 && y<=130){dx=stoi(input_word(xs1, 110, xs2, 130)); return;}
   if(x>=xs1 && x<=xs2/2 && y>=220 && y<=240){about_programm(); return;}
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

//��������� ����� ����� ��� �������� �����
string input_word(const int startX, const int startY, const int endX, const int endY) {
   string a;
   setbkcolor(NO_COLOR);
   setfillstyle(1,WHITE);
   setcolor(BLACK);
   int f=1;// ����
   int ch;
   string word;
   int len = word.size();
   int x1 = startX, y1 = startY;
   while (1){
      f=1;
      if(word.size()>50) f=0;
      ch = getch();
      if (ch == KEY_ENTER) break;
      if (ch == KEY_ESC){word="Noname.txt"; break;}
      else if (ch == KEY_BACKSPACE && len > 0) word.erase(--len, 1);
      else if (ch > ' ' && ch <= 'z' && f && ch!='*'){word += ch; ++len;}
      // ����� �������� �����
      bar(startX, startY, endX, endY);
      rectangle(startX, startY, endX, endY); 
      outtextxy(x1+5, y1+1, word.c_str());
   }
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