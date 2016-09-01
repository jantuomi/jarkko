CPPFLAGS=-std=c++11 -Wall
CC=g++
TARGET=jarkko
SRCDIR=src

all: jarkko

jarkko: $(SRCDIR)/*.cpp
	$(CC) $(SRCDIR)/*.cpp $(CPPFLAGS) -o $(TARGET)

clean:
	rm $(TARGET)
