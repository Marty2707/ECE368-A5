WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

a5: a5.o
	$(GCC) a5.o -o a5

a5.o: a5.c
	$(GCC) -c a5.c -o a5.o

clean:
	rm -f *.o a5
