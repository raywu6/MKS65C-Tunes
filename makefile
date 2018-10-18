all: llist.o musiclib.o
	gcc driver.c llist.o musiclib.o

run: all
	./a.out

llist.o: llist.c llist.h musiclib.c musiclib.h
	gcc -c llist.c musiclib.c

test.o: driver.c llist.h musiclib.h
	gcc -c driver.c

clean:
	rm *~ *.gch* a.out *.o *#*
