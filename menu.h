#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "graphics.h"

using namespace std;

extern int wx, wy;// ������� ����
extern string filename;//��� �����
extern int dx, dy;//������� ����

void draw_menu(); //��������� ����
string input_word(const int startX, const int startY, const int endX, const int endY); //��������� ����� ����� ��� ��������� � �� ����������

#endif  /* MENU */