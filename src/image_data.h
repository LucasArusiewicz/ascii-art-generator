#ifndef IMAGE_DATA_H
#define IMAGE_DATA_H

// Um pixel RGB
typedef struct
{
    unsigned char r, g, b;
} RGB;

// Uma imagem em RGB
typedef struct
{
    int width, height;
    RGB *img;
} Img;

void load_image_file(const char *name, Img *pic);
void save_image_file(const char *name, Img *pic);
int calcula_intensidade(RGB *pixel);
void image_to_gray(Img *pic);

#endif