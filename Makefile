CC      = gcc
CFLAGS  = -Wall -Wextra -g -Iinclude
SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)
TARGET  = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
