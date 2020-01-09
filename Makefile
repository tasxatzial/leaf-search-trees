CFLAGS = -c -ansi -Wall -pedantic

lbst: main.o lbst.o
	gcc main.o lbst.o -o lbst

main.o: main.c lbst_public.h
	gcc $(CFLAGS) main.c

lbst.o: lbst.c lbst.h
	gcc $(CFLAGS) lbst.c

clean:
	rm -rf *.o lbst