CC = gcc
CFLAGS = -Wall -Wextra -pedantic 
TARGETS = variable_types control_flow loops functions arrays_strings pointers_intro

all: $(TARGETS)

$(TARGETS): %: %/%.c
	$(CC) $(CFLAGS) -o build/$@ $</$@.c

clean:
	rm -f $(OUT)

.PHONY: all clean
