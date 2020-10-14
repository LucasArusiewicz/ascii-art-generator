# Makefile for Linux and macOS

PROG = ascii-art-generator
FONTES = src/main.c src/utility/image_data.c src/utility/output_data.c lib/SOIL/image_DXT.c lib/SOIL/image_helper.c lib/SOIL/SOIL.c lib/SOIL/stb_image_aug.c
OBJETOS = $(FONTES:.c=.o)
CFLAGS = -Wall -g -DGL_SILENCE_DEPRECATION
LDFLAGS =  -lopengl32 -lm

UNAME = `uname`

all: $(TARGET)
	-@make $(UNAME)

Darwin: $(OBJETOS)
	gcc $(OBJETOS) -O3 -Wno-deprecated -framework OpenGL -framework Cocoa -lm -o $(PROG)

Linux: $(OBJETOS)
	gcc $(OBJETOS) -O3 -lGL -lm -o $(PROG)

clean:
	-@ rm -f $(OBJETOS) $(PROG)
