CC=gcc
CFLAGS=-O3 -Werror -Wextra -std=c99
OUT=main
FILESq2=question02/main.c
q2:
	$(CC) $(FILESq2) $(CFLAGS) -o $(OUT)
clean:
	rm -rf *~ *.o $(OUT)
