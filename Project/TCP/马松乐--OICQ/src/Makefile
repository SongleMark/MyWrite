CC		= gcc
CXX		= g++
TARGET  = client server
CLIBS	= -lpthread 
SLIBS	= -lpthread -lmysqlclient
COBJECT = cli.o socket.o
SOBJECT = sec.o socket.o mysql.o afterlog.o
FLAG	=  -g -o
INCLUDE = -I../inc/

all:$(TARGET)

client:$(COBJECT) 
	$(CC) $(COBJECT)  $(FLAG) client $(CLIBS)

server:$(SOBJECT)
	$(CC) $(SOBJECT)  $(FLAG) server $(SLIBS)

socket.o:socket.c
	$(CC) -c socket.c $(INCLUDE) $(FLAG) socket.o

cli.o:cli.c
	$(CC) -c cli.c $(INCLUDE) $(FLAG) cli.o 

sec.o:sec.c
	$(CC) -c sec.c $(INCLUDE) $(FLAG) sec.o

mysql.o:mysql.c
	$(CC) -c mysql.c $(INCLUDE) $(FLAG) mysql.o

afterlog.o:afterlog.c
	$(CC) -c afterlog.c $(INCLUDE) $(FLAG) afterlog.o

clean:
	rm *.o
