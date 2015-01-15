CC=gcc
CFLAGS=-O0 -Werror -Wextra -std=c99
OUT=main
FILES=main.c
all:
	$(CC) $(FILES) $(CFLAGS) -o $(OUT)
clean:
	rm -rf *~ *.o $(OUT)
