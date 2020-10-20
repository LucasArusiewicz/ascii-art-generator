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

    load_image_file(argv[1], &pic);
    image_to_gray(&pic);
    save_image_file("out.bmp", &pic);
    save_html("saida.html", "oi");
    free(pic.img);
}
