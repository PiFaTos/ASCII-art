#include<menu.hpp>
#include<iostream>
#include<graphics.h>
#include <vector>
#include <fstream>
#include<convert_image_to_ascii.hpp>
#include<save_to_png_txt.h>
IMAGE *bgpic;
IMAGE *pic;
using namespace std;

int xs1=20, xs2=435;

//Рисование меню
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
   outtextxy(xs1+5, 61, filename.c_str());
   string dx_str=to_string(dx);
   string dy_str=to_string(dy);
   outtextxy(xs1+5, 121, dx_str.c_str());
   outtextxy(xs2/2+15, 121, dy_str.c_str());
   outtextxy(xs1, 45, "Имя файла");
   outtextxy(xs1, 105, "Ширина");
   outtextxy(xs2/2+10, 105, "Высота");
   outtextxy(xs1+5, 180, "Сгенерировать");
   outtextxy(xs1+5, 240, "Очистить");
   outtextxy(xs1+5, 300, "О программе");
}
//Основной цикл для проверки нажатия
void cycle(){
   int m;
   while(1){
      if(kbhit(1)){
         m=getch(2);
         if(m==MOUSE_LCLICK){
            int x=mousex();  int y=mousey();
            prov_pole(x, y);
            cout<<"1\n";
         }
      }
   }
}
//Проверка кнопки
void prov_pole(int x, int y){
   if(x>=xs1 && x<=xs2 && y>=240 && y<=260){use_but(2); return;}
   if(x>=xs1 && x<=xs2 && y>=180 && y<=200){use_but(1); return;}
   if(x>=xs1 && x<=xs2 && y>=60 && y<=80){filename=input_word(xs1, 60, xs2, 80, 0); return;}
   if(x>=xs1 && x<=xs2/2-10 && y>=120 && y<=140){dx=stoi(input_word(xs1, 120, xs2/2-10, 140, 1)); return;}
   if(x>=xs2/2+10 && x<=xs2 && y>=120 && y<=140){dy=stoi(input_word(xs2/2+10, 120, xs2, 140, 2)); return;}
   if(x>=xs1 && x<=xs2/2 && y>=300 && y<=320){about_programm(); return;}
   return;
}

//Использование кнопки
void use_but(int i){
   switch(i){
      case 1: generate();break;
      case 2: clear_all(); break;
   }
   return;
}

void draw_cursor(int x, int y, int c) { // рисование мигающего курсора
   setcolor(c);
   line(x, y, x, y+textheight("A")-1);
}

//Рисование имени файла или искомого слова
string input_word(const int startX, const int startY, const int endX, const int endY, const int i){
   setbkcolor(NO_COLOR);
   setfillstyle(1,WHITE);
   setcolor(BLACK);
   int f=1;// Флаг
   int ch;
   int cur=0;
   string word;
   if(!i) word=filename;
   else if(i==1) word=to_string(dx);
   else word=to_string(dy);
   int len=word.size();
   int x1=startX, y1 = startY;
   bar(startX, startY, endX, endY);
   rectangle(startX, startY, endX, endY); 
   setcolor(BLACK);
   outtextxy(x1+5, y1+1, word.c_str());
   while(1){
      draw_cursor(startX+textwidth(word.c_str())+7, startY+2, cur<10?BLACK:WHITE);
      cur=(cur+1)%20;
      if(!kbhit(1)) delay(50);
         else {
            f=1;
            if(!i){if(word.size()>50) f=0;}
            else if(word.size()>8) f=0;
            ch=getch(2);
            if(ch==KEY_ENTER || ch==MOUSE_LCLICK) break;
            if(ch==KEY_ESC){
               if(!i) word="Noname.png";
               else word='0';
               break;
            }
            else if (ch == KEY_BACKSPACE && len>0) word.erase(--len, 1);
            else if (ch>' ' && ch<='z' && f && ch!='*'){
               if(!i){word+=ch; ++len;}
               else if(ch>=48 && ch<=57){word+=ch; ++len;}
            }
            // Вывод текущего ввода
            bar(startX, startY, endX, endY);
            setcolor(BLACK);
            rectangle(startX, startY, endX, endY); 
            outtextxy(x1+5, y1+1, word.c_str());
         }
   }
   bar(startX, startY, endX, endY);
   setcolor(BLACK);
   rectangle(startX, startY, endX, endY); 
   outtextxy(x1+5, y1+1, word.c_str());
   draw_cursor(startX+textwidth(word.c_str())+7, startY+2, WHITE);
   return word;
}

//Очистить значения
void clear_all(){
   draw_menu();
   dx=0, dy=0;
   filename="Noname.png";
}

//Перевод изображения в ascii-art
void generate(){
   pic=loadBMP(filename.c_str());
   IMAGE *pig;
   pig=imageresize(pic, dx, dy, COLORONCOLOR_RESIZE);
   save_to_png_txt(convert_image_to_ascii(pig, dx, dy), dx, dy);
}

//О программе
void about_programm(){
   clearviewport();
   bgpic=loadBMP("O_programme.bmp");
   putimage(0, 0, bgpic,COPY_PUT,getmaxx(),getmaxy());
   getch(2);// ждать нажатия мыши или клавиатуры
   freeimage(bgpic);
   draw_menu();
   return;
}