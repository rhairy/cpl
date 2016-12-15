BIN = bin
SRC = src
ALL = hw 1-3 1-4

all : $(ALL) cp clean

hw : hw.o
1-3 : 1-3.o
1-4 : 1-4.o
clean :
	rm -f *.o $(ALL)
cp : 
	cp $(ALL) ../$(BIN)
