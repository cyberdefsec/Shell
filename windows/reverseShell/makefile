TARGET = reverseShell.exe
#CFLAGS = -Wall -g
CC = gcc
OBJECTS = reverseShell.o execShell.o connect.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)
	
reverseShell.o: reverseShell.c
	$(CC) -c reverseShell.c
	
connect.o: connect.c connect.h
	$(CC) -c connect.c

execShell.o: execShell.c execShell.h
	$(CC) -c execShell.c