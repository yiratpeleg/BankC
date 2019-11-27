CC=gcc
FLAGS= -Wall -g

all:myBanks myBanks mains maind

libmyBank.a:myBank.o myBank.h
	ar rcs libmyBank.a myBank.o myBank.h

myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c

libmyBank.so:myBank.o myBank.h 
	$(CC) -shared -fPIC -o libmyBank.so myBank.o myBank.h

mains:libmyBank.a main.o myBank.h
	$(CC) $(FLAGS) -fPIC -o mains main.o libmyBank.a myBank.h

maind:libmyBank.so main.o myBank.h
	$(CC) $(FLAGS) -fPIC -o maind main.o ./libmyBank.a
	
myBanks:libmyBank.a

myBankd:libmyBank.so

main.o:main.c myBank.h
	$(CC) $(FLAGS) -fPIC -c main.c

.PHONY: clean all	

clean:
	rm -f *.o *.so *.a maind mains