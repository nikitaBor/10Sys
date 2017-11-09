all: main.o
	gcc -o test10 main.o
main.o: main.c
	gcc -c main.c
clean:
	rm main.o test10
run: all
	./test10
