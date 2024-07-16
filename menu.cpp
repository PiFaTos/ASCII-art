#include<menu.h>
#include<iostream>
#include<graphics.h>
#include <vector>

using namespace std;

void draw_menu(){
   setfillstyle(1,COLOR(164, 245, 180));
   bar(0 , 0, wx, wy);
   setfillstyle(1,WHITE);
   //Имя файла
   bar(20, 60, 120, 80);
   rectangle(20, 60, 120, 80);
   outtextxy(20, 40, "Имя файла");
   //Размеры арта
   bar(20, 110, 60, 130);
   rectangle(20, 110, 60, 130);
   outtextxy(20, 90, "Ширина");
   
   bar(80, 110, 120, 130);
   rectangle(80, 110, 120, 130);
   outtextxy(80, 90, "Высота");
   //Сгенерировать
   bar(20, 140, 120, 160);
   rectangle(20, 140, 120, 160);
   outtextxy(25, 145, "Сгенерировать");
   //Очистить
   bar(20, 180, 120, 200);
   rectangle(20, 180, 120, 200);
   outtextxy(25, 185, "Очистить");
}

//Рисование имени файла или искомого слова
string input_word(const int startX, const int startY, const int endX, const int endY) {
   string a;
   setbkcolor(NO_COLOR);
   setfillstyle(1,COLOR(164, 245, 180));
   setcolor(BLACK);
   int f;// Флаг
   int ch;
   string word;
   int len = word.size();
   int x1 = startX, y1 = startY;
   while (1) {
      f=1;
      if(word.size()>50) f=0;
      ch = getch();
      if (ch == KEY_ENTER) break;
      if (ch == KEY_ESC){word="Noname.html"; break;}
      else if (ch == KEY_BACKSPACE && len > 0) word.erase(--len, 1);
      else if (ch > ' ' && ch <= 'z' && f && ch!='*'){word += ch; ++len;}
      // Вывод текущего ввода
      bar(startX, startY, endX, endY);
      rectangle(startX, startY, endX, endY); 
      outtextxy(x1+5, y1+5, word.c_str());
   }
   return word;
}