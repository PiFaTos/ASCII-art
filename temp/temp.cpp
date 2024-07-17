//���� ������������ ��� ���������� ����������� � TXT ����





using namespace std;
using namespace filesystem;

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
   //�������� ���������� ����� ��� ������ �� ����� ART
   ofstream outfile("ART/ascii_art.txt");
   // ������ ASCII-���� � ��������� ����
   outfile.write(ascii_data.data(), _abracadabra_cast(ascii_data);