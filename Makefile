CC=gcc
BIN_NAME = cli-startup

cli-startup: config.o main.o
	gcc -o ./build/cli-startup ./build/config.o ./build/main.o

config.o: ./src/config.c
	gcc -o ./build/config.o ./src/config.c -c

main.o: ./src/main.c
	gcc -o ./build/main.o ./src/main.c -c

clean:
	rm ./build/*.o
