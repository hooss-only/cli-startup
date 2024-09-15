CC=gcc
BIN_NAME = cli-startup

cli-startup: config.o print_logo.o wise_saying.o main.o
	gcc -o ./build/cli-startup ./build/config.o ./build/print_logo.o ./build/wise_saying.o ./build/main.o 

config.o: ./src/config.c
	gcc -o ./build/config.o ./src/config.c -c

print_logo.o: ./src/utils/print_logo.c
	gcc -o ./build/print_logo.o ./src/utils/print_logo.c -c

wise_saying.o: ./src/utils/wise_saying.c
	gcc -o ./build/wise_saying.o ./src/utils/wise_saying.c -c

main.o: ./src/main.c
	gcc -o ./build/main.o ./src/main.c -c

clean:
	rm ./build/*.o
