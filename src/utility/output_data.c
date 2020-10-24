#include <stdio.h>
#include <stdlib.h>
#include "../image_data.h"
#include "../output_data.h"

void save_html(const char *name, Img *pic, char *map, int sizeMap, int widthBlock, int heightBlock)
{
    FILE *arq = fopen(name, "w");
    if (arq == NULL)
    {
        printf("Erro abrindo arquivo de saída\n");
        exit(1);
    }

    // Escrita do cabeçalho
    fprintf(arq, "<html>\n");
    fprintf(arq, "<head>\n");
    fprintf(arq, "</head>\n");
    fprintf(arq, "<body style=\"background: black; color: white; margin: 0px; font-family: monospace;\">\n");

    // Escrita do corpo
    for (int x = 0; x < pic->width; x += widthBlock)
    {
        char *buf = calloc(pic->width, sizeof *buf);
        int i = 0;
        for (int y = 0; y < pic->height; y += heightBlock)
        {
            int pos = (y * pic->width) + x;
            buf[i] = gray_to_ascii(pic->img[pos].r, map, sizeMap);
            i++;
        }

        fprintf(arq, buf);
        fprintf(arq, "<br>\n");
        free(buf);
    }

    // Escrita do rodapé
    fprintf(arq, "</body>\n");
    fprintf(arq, "</html>\n");
    fclose(arq);
}