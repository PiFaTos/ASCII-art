#include<menu.hpp>
#include<iostream>
#include<graphics.h>
#include <vector>
#include <fstream>
using namespace std;

//��������� ����
void draw_menu(){
   setfillstyle(1,COLOR(164, 245, 180));
   bar(0 , 0, wx, wy);
   setfillstyle(1,WHITE);
   //��� �����
   bar(20, 60, 120, 80);
   rectangle(20, 60, 120, 80);
   outtextxy(20, 40, "��� �����");
   //������� ����
   bar(20, 110, 60, 130);
   rectangle(20, 110, 60, 130);
   outtextxy(20, 90, "������");
   
   bar(80, 110, 120, 130);
   rectangle(80, 110, 120, 130);
   outtextxy(80, 90, "������");
   //�������������
   bar(20, 140, 120, 160);
   rectangle(20, 140, 120, 160);
   outtextxy(25, 145, "�������������");
   //��������
   bar(20, 180, 120, 200);
   rectangle(20, 180, 120, 200);
   outtextxy(25, 185, "��������");
}

//�������� ������
int prov_but(int x, int y){
   if(x>=20 && x<=120 && y>=140 && y<=160) use_but(1);
   if(x>=20 && x<=120 && y>=180 && y<=200) use_but(2);
   return;
}

//������������� ������
void use_but(int i){
   switch(i){
      case 1: generate();
      case 2: clear_all();
   }
}

//��������� ����� ����� ��� �������� �����
string input_word(const int startX, const int startY, const int endX, const int endY) {
   string a;
   setbkcolor(NO_COLOR);
   setfillstyle(1,COLOR(164, 245, 180));
   setcolor(BLACK);
   int f;// ����
   int ch;
   string word;
   int len = word.size();
   int x1 = startX, y1 = startY;
   while (1) {
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
