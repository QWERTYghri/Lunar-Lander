cc = gcc

main : main.c
	$(cc) -o lunar main.c -Wall -pedantic -std=c90 -Wall -g
