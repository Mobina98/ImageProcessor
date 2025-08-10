CC=g++
CFLAGS=-c -Wall -fopenmp -std=c++20
LDFLAGS=-fopenmp
SOURCES=main.cpp methods.cpp
HEADERS=bmp.h methods.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

doc:
	doxygen Doxyfile
