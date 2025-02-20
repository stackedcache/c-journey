CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -pedantic 
SRC = src/main.c
OUT = build/main

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OBJ) $(OUT)

.PHONY: all clean
