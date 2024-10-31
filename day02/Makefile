# this is a comment

# target: dependencies
#   action

main.o: main.c
	clang -c main.c

main: main.o
	clang main.o -o main

run: main
	./main

clean :
	rm main *.o
