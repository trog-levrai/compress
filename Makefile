CC=gcc
CFLAGS=-O3 -Werror -Wextra -std=c99
OUT=main
FILES=question10.c question2-9.c
all:
	$(CC) $(FILES) $(CFLAGS) -o $(OUT)
clean:
	rm -rf *~ *.o $(OUT)
