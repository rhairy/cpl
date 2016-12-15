CC = gcc
CFLAGS = -Wall -Werror
BIN = bin
ALL = 1-1 1-3 1-4 1-5

all : $(ALL) cp clsrc

1-1 : 1-1.o
1-3 : 1-3.o
1-4 : 1-4.o
1-5 : 1-5.o

clean : rm -rf *.o $(ALL)

clsrc :
	rm -f *.o $(ALL)
cp : 
	cp $(ALL) ../$(BIN)
