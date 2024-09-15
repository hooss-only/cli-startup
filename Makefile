CC=gcc
BIN_NAME = cli-startup

cli-startup: config.o main.o print_logo.o
	gcc -o ./build/cli-startup ./build/config.o ./build/main.o ./build/print_logo.o

config.o: ./src/config.c
	gcc -o ./build/config.o ./src/config.c -c

print_logo.o: ./src/utils/print_logo.c
	gcc -o ./build/print_logo.o ./src/utils/print_logo.c -c

main.o: ./src/main.c
	gcc -o ./build/main.o ./src/main.c -c

clean:
	rm ./build/*.o
