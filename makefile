all: llist.o musiclib.o
	gcc -g driver.c llist.o musiclib.o

run: all
	./a.out

llist.o: llist.c llist.h musiclib.c musiclib.h
	gcc -c -g llist.c musiclib.c

test.o: driver.c llist.h musiclib.h
	gcc -c -g driver.c

clean:
	rm *~ *.gch* a.out *.o *#* ; rm -r *.dSYM
