CC=gcc
FLAGS= -Wall -g

all:myBanks BankExe

libmyBank.a:myBank.o myBank.h
	ar rcs libmyBank.a myBank.o myBank.h

myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c

BankExe:libmyBank.a main.o myBank.h
	$(CC) $(FLAGS) -fPIC -o BankExe main.o libmyBank.a myBank.h

myBanks:libmyBank.a

main.o:main.c myBank.h
	$(CC) $(FLAGS) -fPIC -c main.c

.PHONY: clean all	

clean:
	rm -f *.o *.so *.a BankExe