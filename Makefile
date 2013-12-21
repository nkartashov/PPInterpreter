CC = g++
CFLAGS = -Wall -O2 -ggdb

BINDIR = bin
SOURCEDIR = src
OBJDIR = $(BINDIR)/obj

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%, $(OBJDIR)/%, $(patsubst %.cpp, %.o, $(SOURCES)))

TARGET = $(BINDIR)/ppinterp

$(TARGET): init $(OBJECTS)
	@echo -n 'Linking $@ ...'
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo ' OK'

$(OBJDIR)/%.o: $(SOURCEDIR)/%.cpp
	@echo -n 'Compiling $@ ...'
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo ' OK'

init:
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(BINDIR) 
	
.PHONY: clean init
	