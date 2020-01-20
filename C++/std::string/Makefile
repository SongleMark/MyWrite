CC		= gcc
CXX		= g++
CFLAG	= -c -g -o
TARGET  = stringToChar
OBJECT1	= stringToChar.o 
FILE1	= stringToChar.cpp
CLEAN	= rm *.o

all:$(TARGET)

stringToChar:stringToChar.o
	$(CXX) $(OBJECT1) -o  stringToChar

stringToChar.o:$(FILE1)
	$(CXX)  $(FILE1) $(CFLAG) stringToChar.o

clean:
	$(CLEAN)

