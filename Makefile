add.out: add.o
	gcc -o add.out add.o

add.o: add.c
	gcc -c -o add.o add.c

clean:
	rm -f add.o
	rm -f add.out
