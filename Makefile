CC=g++
CFLAGS=-c -Wall -fopenmp
LDFLAGS=-std=c++20 -fopenmp
SOURCES=main.cpp methods.cpp
HEADERS=bmp.h methods.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

doc:
	doxygen Doxyfile