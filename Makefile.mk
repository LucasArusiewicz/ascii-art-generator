# Makefile for Windows

PROG = ascii-art-generator.exe
FONTES = src\main.c src\utility\image_data.c src\utility\output_data.c lib\SOIL\image_DXT.c lib\SOIL\image_helper.c lib\SOIL\SOIL.c lib\SOIL\stb_image_aug.c
OBJETOS = $(FONTES:.c=.o)
CFLAGS = -Wall -g
LDFLAGS =  -lopengl32 -lm
CC = gcc

$(PROG): $(OBJETOS)
	gcc $(CFLAGS) $(OBJETOS) -o $@ $(LDFLAGS)

clean:
	-@ del $(OBJETOS) $(PROG)