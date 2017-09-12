all: test

CFLAGS = -g -O2

test: mytoc.o strlib2.o test.o
	cc -o test mytoc.o strlib2.o test.o
clean:
	rm -f  *.o test test.exe
