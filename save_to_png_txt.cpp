#include <iostream>
#include <vector>
#include <fstream>
#include <uchar.h>
#include <filesystem>

using namespace std;
using namespace filesystem;

void save_to_png_txt(const vector<char8_t> &ascii_data, int width, int height) {
   // Открытие текстового файла для записи
   ofstream outfile("Arts/ascii_art.txt");
   if (!outfile.is_open()) {
      cerr << "Failed to open file for writing" << endl;
      return; // Можно добавить обработку ошибки или просто выйти
   }
   outfile.write("\xEF\xBB\xBF", 3);
   // Запись ASCII-арта в текстовый файл
   outfile.write((const char *)ascii_data.data(), ascii_data.size());
   // Закрытие текстового файла
   outfile.close();
}

