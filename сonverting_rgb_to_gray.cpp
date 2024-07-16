#include<onverting_rgb_to_gray.hpp>
#include<iostream>
#include <vector>

using namespace std;

// Преобразование RGB в оттенок серого
double converting_rgb_to_gray(int r, int g, int b) {
   return 0.2989 * r + 0.5870 * g + 0.1140 * b;
}

// Преобразование изображения в оттенках серого в формат ASCII
vector<char> convert_image_to_ascii(IMAGE *image, int width, int height) {
   vector<char> ascii_data(width * height);

   for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
         int pixel_color = imagegetpixel(image, x, y);
         int r = (pixel_color & image->r_mask) >> image->r_shift;
         int g = (pixel_color & image->g_mask) >> image->g_shift;
         int b = (pixel_color & image->b_mask) >> image->b_shift;
         double gray = converting_rgb_to_gray(r, g, b);

         char ascii_char = ' ';
         if (gray < 51) {
            ascii_char = '\u2588'; // Full block
         } else if (gray < 102) {
            ascii_char = '\u2593'; // Dark shade
         } else if (gray < 153) {
            ascii_char = '\u2592'; // Medium shade
         } else if (gray < 204) {
            ascii_char = '\u2591'; // Light shade
         } else {
            ascii_char = ' '; // Space
         }
         ascii_data[y * width + x] = ascii_char;
      }
   }

   return ascii_data;
}