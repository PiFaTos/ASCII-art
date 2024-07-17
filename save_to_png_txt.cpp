#include <iostream>
#include <vector>
#include <fstream>
#include <uchar.h>
#include <filesystem>

using namespace std;
using namespace filesystem;

void save_to_png_txt(const vector<char8_t> &ascii_data, int width, int height) {
   // �������� ���������� ����� ��� ������
   ofstream outfile("Arts/ascii_art.txt");
   if (!outfile.is_open()) {
      cerr << "Failed to open file for writing" << endl;
      return; // ����� �������� ��������� ������ ��� ������ �����
   }
   outfile.write("\xEF\xBB\xBF", 3);
   // ������ ASCII-���� � ��������� ����
   outfile.write((const char *)ascii_data.data(), ascii_data.size());
   // �������� ���������� �����
   outfile.close();
}

