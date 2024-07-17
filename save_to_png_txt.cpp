//���� ������������ ��� ���������� ����������� � TXT ����
#include <iostream>
#include <vector>
#include <fstream> 
#include <uchar.h>

using namespace std;

/*
���������� �������� ������� � ����� 
vector<char> convert_inage_to_ascii(IMAGE *image, int width, int height)
��� ������� ���������� ������ ��������, ������ ������ ����������� � ���� Unicode
https://en.wikipedia.org/wiki/List_of_Unicode_characters#:~:text=U%2B2591,Dark%20shade
*/

/*
������� save_to_png_txt ��������� � ���� ������, ������� ����� ������ � ������ ������� 
����� �������� � txt ����
*/

/*
������ ������ �������:

vector<char> ascii_data = convert_image_to_ascii(image, width, height);
save_to_png_txt(ascii_data, width, height);

���� ��� ������� ����������� ����������� � ASCII-��� � ������� ������� convert_image_to_ascii, 
� ����� �������� ���������� ������ � ���� ascii_art.txt � ������� ������� save_to_png_txt.
*/
void save_to_png_txt(const vector<char8_t>& ascii_data, int width, int height) {
   //�������� �� �������� ����� ART
   if (!fs::exists("ART")) {
      fs::create_directory("ART");
   }
   
   //�������� ���������� ����� ��� ������ �� ����� ART
   ofstream outfile("ART/ascii_art.txt");
       // ������ ASCII-���� � ��������� ����
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            outfile.write(reinterpret_cast<const char*>(&ascii_data[(i * width + j) * 4]), 4);
        }
        outfile.write(reinterpret_cast<const char*>(u8"\n"), 1);
    }
   
   // �������� ���������� �����
   outfile.close();
}

