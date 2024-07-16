#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "graphics.h"

using namespace std;

extern int wx, wy;// Размеры окна
extern string filename;//Имя файла
extern int dx, dy;//Размеры арта

void draw_menu(); //Рисование меню
string input_word(const int startX, const int startY, const int endX, const int endY); //Рисование имени файла или координат и их сохранение

#endif  /* MENU */