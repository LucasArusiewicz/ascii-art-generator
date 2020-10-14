#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SOIL.h"   // SOIL é a biblioteca para leitura das imagens
#include "image_data.h"
#include "output_data.h"

int main(int argc, char** argv)
{
    Img pic;
    if(argc == 1) {
        printf("loader [img]\n");
        exit(1);
    }
    load_image_file(argv[1], &pic);

    // Inverte as cores
    for(int i=0; i<pic.width*pic.height; i++) {
        pic.img[i].r = 255 - pic.img[i].r;
        pic.img[i].g = 255 - pic.img[i].g;
        pic.img[i].b = 255 - pic.img[i].b;
    }

    save_image_file("out.bmp", &pic);

    save_html("saida.html", "oi");

    free(pic.img);
}
