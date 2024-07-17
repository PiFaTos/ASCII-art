#include<convert_image_to_ascii.hpp>
#include<iostream>
#include <vector>
#include<graphics.h>

using namespace std;

// Преобразование изображения в оттенках серого в формат ASCII
vector<char8_t> convert_image_to_ascii(IMAGE *image, int width, int height) {
    vector<char8_t> ascii_data(width * height * 4); // 4 байта на символ UTF-8

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_color = imagegetpixel(image, x, y);
            int r = (pixel_color >> 16) & 0xFF; // Red component
            int g = (pixel_color >> 8) & 0xFF; // Green component
            int b = pixel_color & 0xFF; // Blue component
            // Преобразование RGB в оттенок серого
            double gray = 0.2989 * r + 0.5870 * g + 0.1140 * b;

            const char8_t* ascii_char;
            if (gray < 51) {
                ascii_char = u8"\u2588"; // Full block
            } else if (gray < 102) {
                ascii_char = u8"\u2593"; // Dark shade
            } else if (gray < 153) {
                ascii_char = u8"\u2592"; // Medium shade
            } else if (gray < 204) {
                ascii_char = u8"\u2591"; // Light shade
            } else {
                ascii_char = u8" "; // Space
            }

            // Добавление UTF-8 символа в массив
            for (const char8_t* p = ascii_char; *p != '\0'; ++p) {
                ascii_data.push_back(*p);
            }
        }
        // Добавление перевода строки в конце каждой строки изображения
        ascii_data.push_back(u8'\n');
    }

    return ascii_data;
}