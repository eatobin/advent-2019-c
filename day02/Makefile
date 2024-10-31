# this is a comment

# target: dependencies
#   action

file_fns.o: file_fns.c
	clang -c file_fns.c

main.o: main.c
	clang -c main.c

main: main.o file_fns.o
	clang main.o file_fns.o -o main

run: main
	./main

clean :
	rm main *.o
