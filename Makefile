CFLAGS = -c -ansi -Wall -pedantic

lbst: main.o lbst.o lbst_helper.o
	gcc main.o lbst.o lbst_helper.o -o lbst

lbst_helper.o: lbst_helper.c lbst_helper.h lbst.h lbst_public.h
	gcc $(CFLAGS) lbst_helper.c

main.o: main.c lbst_public.h lbst_helper.h
	gcc $(CFLAGS) main.c

lbst.o: lbst.c lbst.h lbst_public.h
	gcc $(CFLAGS) lbst.c

clean:
	rm -rf *.o lbst