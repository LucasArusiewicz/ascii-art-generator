#include <stdio.h>
#include <stdlib.h>
#include "../SOIL.h"
#include "../image_data.h"

void load_image_file(const char* name, Img* pic)
{
    int chan;
    pic->img = (unsigned char*) SOIL_load_image(name, &pic->width, &pic->height, &chan, SOIL_LOAD_RGB);
    if(!pic->img)
    {
        printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
        exit(1);
    }
    
    printf("Load: %d x %d x %d\n", pic->width, pic->height, chan);
}

void save_image_file(const char* name, Img* pic)
{
    SOIL_save_image(
        name,
        SOIL_SAVE_TYPE_BMP,
        pic->width,
        pic->height,
        3,
        (const unsigned char*) pic->img
    );
}