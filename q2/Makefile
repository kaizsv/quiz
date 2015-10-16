CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c timer.c
	$(CC) $(CFLAGS_common) -o $@ $@.c timer.c

recursive: recursive.c timer.c
	$(CC) $(CFLAGS_common) -o $@ $@.c timer.c

clean:
	$(RM) $(EXEC) *.o perf.*
