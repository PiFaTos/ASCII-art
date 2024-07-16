#include<menu.hpp>
#include<iostream>
#include<graphics.h>
#include <vector>
#include <fstream>

using namespace std;

int xs1=20, xs2=120;

//��������� ����
void draw_menu(){
   setfillstyle(1,COLOR(164, 245, 180));
   bar(0 , 0, wx, wy);
   setfillstyle(1,WHITE);
   //��� �����
   bar(xs1, 60, xs2, 80);
   rectangle(xs1, 60, xs2, 80);
   outtextxy(xs1, 40, "��� �����");
   //������� ����
   bar(xs1, 110, xs2/2, 130);
   rectangle(xs1, 110, xs2/2, 130);
   outtextxy(xs1, 90, "������");
   
   bar(xs2-40, 110, xs2, 130);
   rectangle(xs2-40, 110, xs2, 130);
   outtextxy(xs2-40, 90, "������");
   //�������������
   bar(xs1, 140, xs2, 160);
   rectangle(xs1, 140, xs2, 160);
   outtextxy(xs1+5, 145, "�������������");
   //��������
   bar(xs1, 180, xs2, 200);
   rectangle(xs1, 180, xs2, 200);
   outtextxy(xs1+5, 185, "��������");
   //� ���������
   bar(xs1, 220, xs2, 240);
   rectangle(xs1, 220, xs2, 240);
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
      case 1: generate(); break;
      case 2: clear_all(); break;
   }
   return;
}

//��������� ����� ����� ��� �������� �����
string input_word(const int startX, const int startY, const int endX, const int endY) {
   string a;
   setbkcolor(WHITE);
   setfillstyle(1,COLOR(164, 245, 180));
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
      outtextxy(x1+5, y1+5, word.c_str());
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