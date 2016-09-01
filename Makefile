CPPFLAGS=-std=c++11 -Wall
CC=g++
TARGET=jarkko

all: jarkko

jarkko: *.cpp
	$(CC) *.cpp $(CPPFLAGS) -o $(TARGET)

clean:
	rm $(TARGET)
