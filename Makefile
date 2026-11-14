CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -g
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
TARGET = sistema_redes

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

run: all
	./$(TARGET)

# Verifica vazamento de memoria (requer valgrind instalado)
valgrind: all
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -rf build $(TARGET)

.PHONY: all run valgrind clean
