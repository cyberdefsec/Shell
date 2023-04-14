TARGET = reverseShell
PREFIX = /sbin
CFLAGS = -Wall -Wextra
CC = gcc
OBJECTS = reverseShell.o execShell.o connect.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)	
	
reverseShell.o: reverseShell.c
	$(CC) $(CFLAGS) -c reverseShell.c

execShell.o: execShell.c execShell.h
	$(CC) $(CFLAGS) -c execShell.c
	
connect.o: connect.c connect.h
	$(CC) $(CFLAGS) -c connect.c
	
clean:
	rm -rf *.o $(TARGET)
	
install: 
	install $(TARGET) $(PREFIX)
	
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
