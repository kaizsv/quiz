CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c build_list.c
	$(CC) $(CFLAGS_common) -o $@ $@.c build_list.c

recursive: recursive.c build_list.c
	$(CC) $(CFLAGS_common) -o $@ $@.c build_list.c

clean:
	$(RM) $(EXEC) *.o perf.*
