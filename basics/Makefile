# Makefile generated with AI guidance, iteratively learning and tweaking
# Handles recursive compilation, directory creation, and cleanup

CC = gcc
CFLAGS = -Wall -Wextra -pedantic
BUILD_DIR = ../build/basics

# Recursively find all .c files
SOURCES = $(shell find . -type f -name '*.c')

# Map each .c source file to corresponding ../build/ executable
BINARIES = $(patsubst ./%, $(BUILD_DIR)/%, $(basename $(SOURCES)))

.PHONY: all clean

# Build everything
all: $(BINARIES)

# Compile each .c file to ../build/, keeping subdir structure but removing .c extension
$(BUILD_DIR)/%: ./%.c
	@echo "Compiling $< -> $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $<

# Clean executables AND remove build subdirectories that no longer exist in basics/
clean:
	@echo "Cleaning executables in $(BUILD_DIR)..."
	find $(BUILD_DIR) -type f -executable -delete

	@echo "Removing stale directories in $(BUILD_DIR)..."
	# Sync directories: remove from build/ if not in basics/
	@find $(BUILD_DIR) -type d | while read dir; do \
		relative_dir=$${dir#$(BUILD_DIR)/}; \
		[ "$$relative_dir" = "" ] && continue; \
		[ -d "./$$relative_dir" ] || { \
			echo "Removing stale directory: $$dir"; \
			rm -rf "$$dir"; \
		}; \
	done
