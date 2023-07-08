all: compile link

compile:
	g++ -c main.cpp -Isrc/include -DSFML_STATIC

link:
	g++ main.o -o main -Lsrc/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows