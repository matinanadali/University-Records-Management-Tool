INCLUDE = -I./include -I../include
MODULES = ./modules

CC = g++

# Compile options
CFLAGS = -Wall -Werror $(INCLUDE)
LDFLAGS = -lm

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# Object files for native build
OBJS = $(MODULES)/Person.o $(MODULES)/main.o $(MODULES)/Secretary.o $(MODULES)/Professor.o $(MODULES)/Student.o  $(MODULES)/Course.o $(MODULES)/General.o

EXEC = main

# Default target (native build with GCC)
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

run: $(EXEC)
	./$(EXEC) $(ARGS)

