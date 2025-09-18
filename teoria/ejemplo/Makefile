CC = g++
CFLAGS = -Wall -g

SOURCES = main.cpp library.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = library.h

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $<