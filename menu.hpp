#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include "graphics.h"

using namespace std;

extern int wx, wy;// Размеры окна
extern string filename;//Имя файла
extern int dx, dy;//Размеры арта

void generate();//Создать изображение
void clear_all();//Очистить значения
int prov_but(int x, int y);//Проверка кнопки
void use_but(int i);//Использование кнопки
void draw_menu(); //Рисование меню
string input_word(const int startX, const int startY, const int endX, const int endY); //Рисование имени файла или координат и их сохранение

#endif  /* MENU */