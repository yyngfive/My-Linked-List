list:list.o
	gcc -o list list.o
list.o:list.c list.h
	gcc -c list.c 
	
clear:
	rm list.o

