# this is a comment

# target: dependencies
#   action

file_fns.o: file_fns.c
	clang -c file_fns.c

day02.o: day02.c
	clang -c day02.c

day02: day02.o file_fns.o
	clang day02.o file_fns.o -o day02

run: day02
	./day02

clean :
	rm day02 *.o
