# this is a comment

# target: dependencies
#   action

day01.o: day01.c
	clang -c day01.c

day01: day01.o
	clang day01.o -o day01

run: day01
	./day01

clean :
	rm day01 *.o
