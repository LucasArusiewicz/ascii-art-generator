#include <stdio.h>
#include <stdlib.h>
#include "../SOIL.h"
#include "../image_data.h"

void load_image_file(const char *name, Img *pic)
{
    int chan;
    pic->img = (unsigned char *)SOIL_load_image(name, &pic->width, &pic->height, &chan, SOIL_LOAD_RGB);
    if (!pic->img)
    {
        printf("SOIL loading error: '%s'\n", SOIL_last_result());
        exit(1);
    }

    printf("Load: %d x %d x %d\n", pic->width, pic->height, chan);
}

void save_image_file(const char *name, Img *pic)
{
    SOIL_save_image(
        name,
        SOIL_SAVE_TYPE_BMP,
        pic->width,
        pic->height,
        3,
        (const unsigned char *)pic->img);
}

int calcula_intensidade(RGB *pixel)
{
    return 0.3 * pixel->r + 0.59 * pixel->g + 0.11 * pixel->b;
}

// Conforme item 2.2 do enunciado disponibilizado https://mflash.github.io/progswb2/trab/t1-202-hjb7fyhdc/
void image_to_gray(Img *pic)
{
    for (int i = 0; i < (pic->width * pic->height); i++)
    {
        int intensidade = calcula_intensidade(&pic->img[i]);
        pic->img[i].r = intensidade;
        pic->img[i].g = intensidade;
        pic->img[i].b = intensidade;
    }
}

void group_pixel(Img *pic, int widthBlock, int heightBlock)
{

    // Calcula area valida para m
    int maxWidth = pic->width - (pic->width % widthBlock);
    int maxHeight = pic->height - (pic->height % heightBlock);

    for (int x = 0; x < maxWidth; x += widthBlock)
    {
        for (int y = 0; y < maxHeight; y += heightBlock)
        {
            int media = 0;

            // Laço para calcular a média do bloco
            for (int i = 0; i < heightBlock; i++)
            {
                for (int j = 0; j < widthBlock; j++)
                {
                    int pos = ((i + y) * maxWidth) + (j + x);
                    media += pic->img[pos].r;
                }
            }

            // Finaliza calculo da média
            media /= widthBlock * heightBlock;

            // Laço para definir novo valor do bloco
            for (int i = 0; i < heightBlock; i++)
            {
                for (int j = 0; j < widthBlock; j++)
                {
                    int pos = ((i + y) * maxWidth) + (j + x);
                    pic->img[pos].r = media;
                    pic->img[pos].g = media;
                    pic->img[pos].b = media;
                }
            }
        }
    }
    pic->width = maxWidth;
    pic->height = maxHeight;
}

char gray_to_ascii(int gray, char *map, int sizeMap)
{
    int block = 256 / sizeMap;
    for (int i = 0; i < sizeMap; i++)
    {
        if (gray < block * (i + 1))
        {
            return map[i];
        }
    }
    return map[sizeMap - 1];
}