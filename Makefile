CC=gcc
BIN_NAME = cli-startup

main: ./src/main.c
	$(CC) -o ./build/$(BIN_NAME) ./src/main.c
