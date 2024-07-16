#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <fstream>
#include<graphics.h>

using namespace std;

extern int wx, wy;// ������� ����
extern string filename;//��� �����
extern int dx, dy;//������� ����

void generate();//������� �����������
void clear_all();//�������� ��������
int prov_but(int x, int y);//�������� ������
void use_but(int i);//������������� ������
void draw_menu(); //��������� ����
string input_word(const int startX, const int startY, const int endX, const int endY); //��������� ����� ����� ��� ��������� � �� ����������

#endif  /* MENU */