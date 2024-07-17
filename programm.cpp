#include <menu.hpp>
#include <filesystem>
#include <graphics.h>
using namespace std;
using namespace filesystem;

int wx = 500, wy = 600;//размеры окна
int dx=0, dy=0;//Размеры арта
string filename="image.jpg"; //Имя файла
fstream file;

int main(void){
   initwindow(wx, wy, "ASCII-arts");
   draw_menu();
   //Папка для файлов
   if(!exists("Arts")) create_directory("Arts");
   //Файл для работы
   file.open(filename);
   cycle();
   file.close();
   closegraph();
   return 0;
}