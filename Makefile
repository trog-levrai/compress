CC=gcc
CFLAGS=-O3 -Werror -Wextra -std=c99
OUTq2=question2
FILESq2=question02/main.c
q2:
	$(CC) $(FILESq2) $(CFLAGS) -o $(OUTq2)
clean:
	rm -rf *~ *.o $(OUTq2)
