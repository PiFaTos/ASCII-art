#include <save_to_png_txt.h>



void save_to_png_txt(const vector<char8_t> &ascii_data, int width, int height) {
   string filename1=filename.erase(filename.find('.'));
   // Îòêðûòèå òåêñòîâîãî ôàéëà äëÿ çàïèñè
   ofstream outfile("Arts/" + filename+ ".txt");
   if (!outfile.is_open()) {
      cerr << "Failed to open file for writing" << endl;
      return; // Ìîæíî äîáàâèòü îáðàáîòêó îøèáêè èëè ïðîñòî âûéòè
   }
   outfile.write("\xEF\xBB\xBF", 3);
   // Çàïèñü ASCII-àðòà â òåêñòîâûé ôàéë
   outfile.write((const char *)ascii_data.data(), ascii_data.size());
   // Çàêðûòèå òåêñòîâîãî ôàéëà
   outfile.close();
}