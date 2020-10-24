#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SOIL.h"
#include "image_data.h"
#include "output_data.h"

int main(int argc, char **argv)
{
    Img pic;
    if (argc == 1)
    {
        printf("loader [img]\n");
        exit(1);
    }

    const int widthBlock = 4;
    const int heightBlock = 5;

    char map[8] = {'.', ':', 'c', 'o', 'C', '0', '8', '@'};
    // char map[10] = {'.', ',', ':', ';', 'o', 'x', '%', '#', '@', '"'};

    load_image_file(argv[1], &pic);
    image_to_gray(&pic);
    group_pixel(&pic, widthBlock, heightBlock);
    save_image_file("out.bmp", &pic);
    save_html("saida.html", &pic, map, 8, widthBlock, heightBlock);
    free(pic.img);
}
