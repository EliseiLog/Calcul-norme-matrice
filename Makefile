p1: main.o functii.o
	clang -Wall main.o functii.o -lm -o p1

main.o: main.c functii.h
	clang -c -Wall main.c

functii.o: functii.c functii.h
	clang -c -Wall functii.c

.PHONY: clean
clean:
	rm -f *.o
	rm p1
