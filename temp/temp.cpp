//Файл предназначен для сохранения изображения в TXT файл





using namespace std;
using namespace filesystem;

/*
Необходимо смотреть функции у Кости 
vector<char> convert_inage_to_ascii(IMAGE *image, int width, int height)
Это функция возвращает вектор символов, каждый символ представлен в виде Unicode
https://en.wikipedia.org/wiki/List_of_Unicode_characters#:~:text=U%2B2591,Dark%20shade
*/

/*
Функция save_to_png_txt принимает в себе вектор, который будет считан и каждый элемент 
будет сохранен в txt файл
*/

/*
Пример вызова функции:

vector<char> ascii_data = convert_image_to_ascii(image, width, height);
save_to_png_txt(ascii_data, width, height);

Этот код сначала преобразует изображение в ASCII-арт с помощью функции convert_image_to_ascii, 
а затем сохранит полученные данные в файл ascii_art.txt с помощью функции save_to_png_txt.
*/
void save_to_png_txt(const vector<char8_t>& ascii_data, int width, int height) {
   //Открытие текстового файла для записи из папки ART
   ofstream outfile("ART/ascii_art.txt");
   // Запись ASCII-арта в текстовый файл
   outfile.write(ascii_data.data(), _abracadabra_cast(ascii_data);