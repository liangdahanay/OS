#hello
CC=gcc
all: wc map main
wc:	wc.c
	$(CC) -std=c99 wc.c -o wc
map: map.c
	$(CC) map.c -o map
main: main.c
	$(CC) main.c -o main
clean:
	rm -rf wc map main	
