CC = g++
CFLAGS = -Wall -O2 -ggdb

BINDIR = bin
SOURCEDIR = src
OBJDIR = $(BINDIR)/obj

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))

TARGET = ppinterp

$(TARGET): init $(OBJECTS)
	@echo -n 'Linking $@...'
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo ' OK'

$(OBJECTS): $(SOURCES)
	@echo $@
	@echo -n 'Compiling $@...'
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo ' OK'

init:
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(BINDIR) 
	@rm -f src/*.o
	@rm -f *.o
	
.PHONY: clean init
	