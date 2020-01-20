CC		= gcc
CXX		= g++
TARGET  = server client
FLAG	=  -c -g -o
CLEAN	= rm *.o

all:$(TARGET)

server:server.o
	$(CC) server.o -o server

client:client.o
	$(CC) client.o -o client

server.o:server.c
	$(CC) server.c $(FLAG) server.o

client.o:client.c
	$(CC) client.c $(FLAG) client.o

clean:
	$(CLEAN)
