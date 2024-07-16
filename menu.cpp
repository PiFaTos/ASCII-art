#include<menu.h>
#include<iostream>
#include<graphics.h>
#include <vector>

using namespace std;

void draw_menu(){
   setcolor(COLOR(0, 250, 154));
   bar(0 ,0, wx, wy);
   setcolor(WHITE);
   bar()
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
   bar(startX - 5, startY - 5, endX + 5, endY + 5); // Очистка области для ввода
   rectangle(startX, startY, endX, endY); // Рамка для ввода
   outtextxy(620, 20, a.c_str());
   while (1) {
      f=1;
      if(word.size()>50) f=0;
      ch = getch();
      if (ch == KEY_ENTER) break;
      if (ch == KEY_ESC){word="Noname.html"; break;}
      else if (ch == KEY_BACKSPACE && len > 0) word.erase(--len, 1);
      else if (ch > ' ' && ch <= 'z' && f && ch!='*'){word += ch; ++len;}
      // Вывод текущего ввода
      bar(startX - 5, startY - 5, endX + 5, endY + 5);
      rectangle(startX, startY, endX, endY); 
      outtextxy(x1+5, y1+10, word.c_str());
   }
   setfillstyle(1,COLOR(164, 245, 180));
   pereris();
   return word;
}