CC=gcc
CFLAGS=-O3 -Werror -Wextra -std=c99
OUT=main
FILES=main.c
q2:
	$(CC) $(FILES) $(CFLAGS) -o $(OUT)
clean:
	rm -rf *~ *.o $(OUT)
