CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c build_tree.c
	$(CC) $(CFLAGS_common) -o $@ $@.c build_tree.c

recursive: recursive.c build_tree.c
	$(CC) $(CFLAGS_common) -o $@ $@.c build_tree.c

clean:
	$(RM) $(EXEC) *.o perf.*
