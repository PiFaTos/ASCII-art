#include <menu.hpp>
#include <filesystem>
#include <graphics.h>
using namespace std;
using namespace filesystem;

int wx = 500, wy = 600;//размеры окна
int dx=0, dy=0;//Размеры арта
string filename="Noname.png"; //Имя файла
fstream file;

int main(void){
   initwindow(wx, wy, "ASCII-arts");
   draw_menu();
   //Папка для файлов
   if(!exists("Arts")) create_directory("Arts");
   //Файл для работы
   file.open(filename);
   int m;
   while(1){
      if(kbhit(1)){
         m=getch(2);
         if(m==MOUSE_LCLICK){
            int x=mousex();  int y=mousey();
            prov_pole(x, y);
         }
      }
   }
   file.close();
   closegraph();
   return 0;
}