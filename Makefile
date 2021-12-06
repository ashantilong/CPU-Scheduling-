CC=gcc
CFLAGS= -c -Wall -g
GROUPMEMEBER = ashanti&cormac


all: CPU-Scheduling

CPU-Scheduling: cache_function.o main.o access_time.o
	$(CC) -O2 access_time.o cache_function.o main.o -o CPU-Scheduling

cache_function.o: cache_function.c
	$(CC) $(CFLAGS) cache_function.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

access_time.o: access_time.c
	$(CC) $(CFLAGS) access_time.c

clean:
	/bin/rm -f CPU-Scheduling *.o *.gz

run:
	./CPU-Scheduling