CC = gcc
CFLAGS = -Wall -Wextra -pedantic -I../include
SRC = $(wildcard *.c)
OUT = ../build/basics_demo

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

.PHONY: all clean
