#include <menu.hpp>
#include <filesystem>
#include <graphics.h>
using namespace std;
using namespace filesystem;

int wx = 500, wy = 600;//������� ����
int dx=200, dy=100;//������� ����
string filename="image.jpg"; //��� �����
fstream file;

int main(void){
   initwindow(wx, wy, "ASCII-arts");
   draw_menu();
   //����� ��� ������
   if(!exists("Arts")) create_directory("Arts");
   //���� ��� ������
   file.open(filename);
   cycle();
   file.close();
   closegraph();
   return 0;
}