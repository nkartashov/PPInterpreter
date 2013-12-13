CC = g++
CFLAGS = -Wall -O2 -ggdb

BINDIR = bin
SOURCEDIR = src
OBJDIR = $(BINDIR)/obj

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))

TARGET = $(BINDIR)/ppinterp

$(TARGET): init $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

init:
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(BINDIR) 
	
.PHONY: clean init
	