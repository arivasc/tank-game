CXX = g++

INCDIR1 = headerFiles
INCDIR2 = src/include
SRCDIR = sourceFiles
OBJDIR = objectFiles

SRCS = $(wildcard $(SRCDIR)/*.cpp)

OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

EXECUTABLE = main

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -I$(INCDIR1) -I$(INCDIR2) -c $< -o $@ -DSFML_STATIC

.PHONY: compile all link clean

compile: $(OBJS)

all: compile link

#compile: $(OBJS)
#	g++ -c resouceFiles/main.cpp -Isrc/include -DSFML_STATIC

link: $(OBJS)
	$(CXX) $^ -o $(EXECUTABLE) -Lsrc/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows