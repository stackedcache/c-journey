#Root makefile, controls all subdirs
SUBDIRS = basics memory_management file_io networking cybersecurity_tools

all:
	@for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done

.PHONY: all clean
