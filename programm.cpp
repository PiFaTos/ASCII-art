#include <menu.hpp>
#include <filesystem>
#include <graphics.h>
using namespace std;
using namespace filesystem;

int wx = 500, wy = 600;//������� ����
int dx=0, dy=0;//������� ����
string filename="Noname.png"; //��� �����
fstream file;

int main(void){
   initwindow(wx, wy, "ASCII-arts");
   draw_menu();
   //����� ��� ������
   if(!exists("Arts")) create_directory("Arts");
   //���� ��� ������
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