TARGET = bindShell
PREFIX = /sbin
CFLAGS = -Wall -Wextra
CC = gcc
OBJECTS = bindShell.o execShell.o server.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)	
	
reverseShell.o: bindShell.c
	$(CC) $(CFLAGS) -c bindShell.c

execShell.o: execShell.c execShell.h
	$(CC) $(CFLAGS) -c execShell.c
	
server.o: server.c server.h
	$(CC) $(CFLAGS) -c server.c
	
clean:
	rm -rf *.o $(TARGET)
	
install: 
	install $(TARGET) $(PREFIX)
	
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
