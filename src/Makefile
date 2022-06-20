CFLAGS = -c -Wall -pedantic

lbst_demo: main.o lbst.o lbst_private.o
	gcc main.o lbst.o lbst_private.o -o lbst_demo

lbst_private.o: lbst_private.c lbst_private.h
	gcc $(CFLAGS) lbst_private.c

main.o: main.c lbst.h lbst_private.h
	gcc $(CFLAGS) main.c

lbst.o: lbst.c lbst.h lbst_private.h
	gcc $(CFLAGS) lbst.c

clean:
	rm -rf *.o lbst_demo