#include "graphics.h"

int wx=400, wy=400; // размеры окна

typedef struct {
   char equations[MAX_EQUATIONS][MAX_EQUATION_LENGTH]; // Массив для хранения уравнений
   int error_index[MAX_EQUATIONS]; // Индекс массива, в котором допущена ошибка (-1 если ошибок нет)
} Equation;
Equation eqSet;

int text_x=20, text_y=0; //координаты уравнений

void background() {
   /*---------------- Рисуем окно: ----------------*/
   setfillstyle(SOLID_FILL, WHITE);
   
}

void draw_cursor(int x, int y, int c) { // рисование мигающего курсора
   setcolor(c);
   line(x, y, x, y+textheight("A")-1);
}

void clear_character(int x, int y) { // удаление символа
   setfillstyle(SOLID_FILL, WHITE);
   bar(x, y, x+textwidth("A")+5, y+textheight("A"));
}

void entering(int x, int y, char *equations, int MAX_LENGTH, const char *dop, int type, int nomer) { // ввод строки
   int len=strlen(equations);
   setcolor(BLACK);
   setbkcolor(WHITE);
   int cur=0;
   int ch;
   while(!ismouseclick(WM_LBUTTONDOWN)) {
      draw_cursor(x+textwidth(equations)+2, y, cur<10?BLACK:WHITE);
      cur=(cur+1)%20;
      if(!kbhit()) delay(50);
         else {
            ch=getch(1);
            if(ch==KEY_ENTER || ch==KEY_ESC) break;
               else if(ch==KEY_SPECIAL+KEY_SHIFT) continue;
                  else if(ch==KEY_BACKSPACE && len>0) {
                     len--;
                     equations[len]='\0'; // удаление последнего символа
                     clear_character(x+textwidth(equations), y);// удаление с экрана
                     //setcolor(BLACK);
                     //outtextxy(x, y, equations);
                  } else if (strchr(dop, ch)!=NULL && len<MAX_LENGTH-1) {
                        equations[len]=ch;
                        len++;
                        equations[len]='\0';
                        setcolor(BLACK);
                        outtextxy(x, y, equations);
                     }
         }
   }
   draw_cursor(x+textwidth(equations)+2, y, WHITE);
   if(type==2){
      double *a;
      switch(nomer) {
         case 0: a=&x_min; break;
         case 1: a=&x_max; break;
         case 2: a=&y_min; break;
         case 3: a=&y_max; break;
      }
      sscanf(equations, "%lf", a);
   }
}

void entering_equations(int x, int y) { // ввод уравнений
   int equation_area=y/(wy/10);
   text_y=(equation_area*wy/10)+24;
   entering(text_x, text_y, eqSet.equations[equation_area], MAX_EQUATION_LENGTH, "0123456789abcdefghijklmnopqrstuvwxyz()+-*/^=!.", 1, -1);
}


int main() {
   initwindow(wx, wy, "Program");
   background();
   
   int x, y;
   while(1){
      if(ismouseclick(WM_LBUTTONDOWN)){
         clearmouseclick(WM_LBUTTONDOWN);
         x=mousex();
         y=mousey();
         if(x<wx/3){
            entering_equations(x, y);
            redrawing_area();
            int o=wx/3-20;
            for(int i=0; i<10; i++){
               int c=wy*(0.1*i+0.05);
               if(eqSet.equations[i][0]!='\0' && eqSet.error_index[i]!=1) {
                  setcolor(f_color[i]);
                  setfillstyle(SOLID_FILL, f_color[i]);
                  fillellipse(o, c, 5, 5);
               } else {
                  setcolor(WHITE);
                  setfillstyle(SOLID_FILL, WHITE);
                  fillellipse(o, c, 5, 5);
                  }
            }
            for(int i=0; i<MAX_EQUATIONS; i++) {
               if(eqSet.error_index[i]==1) {
                  setcolor(RED);
                  outtextxy(text_x, (i*wy/10)+24, eqSet.equations[i]); // Вывод всех строк уравнений
                  setcolor(BLACK);
               }
            }
         }
         if(entering_ranges(x, y)) {
            if(x_min>x_max || y_min>y_max || x_min==x_max || y_min==y_max){
               setcolor(RED);
               setbkcolor(WHITE);
               outtextxy(Lx, Ny+4, "Пожалуйста, исправьте диапазоны. Должно быть: min<max");
               continue;
            } else {
                  setfillstyle(SOLID_FILL, WHITE);
                  bar(Lx, Ny+4, Lx+402, Ny+20);
               }
            redrawing_area();
         }
      }
   }
   closegraph();
   return 0;
}