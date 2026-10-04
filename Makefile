CC=clang
CFLAGS=-Wall -Wextra -std=c11 -O2

bf: src/main.c
	$(CC) $(CFLAGS) -o $@ $<

test: bf
	sh tests/run.sh

clean:
	rm -f bf

.PHONY: test clean
