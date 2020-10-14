#include <stdio.h>
#include "../output_data.h"

void save_html(const char* name, const char* data)
{
    FILE* arq = fopen(name, "w"); // criar o arquivo: w
    if(arq == NULL) // 0, falso
    {
        printf("Erro abrindo arquivo de saída\n");
        exit(1);
    }

    fprintf(arq, "<html>\n");
    fprintf(arq,"<head>\n");
    fprintf(arq,"</head>\n");
    fprintf(arq,"<body>\n");
    fprintf(arq,"<h1>");
    fprintf(arq,data);
    fprintf(arq,"</h1>\n");
    fprintf(arq,"</body>\n");

    fclose(arq);
}