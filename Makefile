EXEC 	= main
CC		= gcc
CCFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic
PERF_FILE = perf.data*
SOURCES 	= $(wildcard *.cpp)
SOURCES     := $(filter-out $(TESTSOURCES), $(SOURCES))
OBJECTS		= $(SOURCES:%.cpp=%.o)

all: $(EXECUTABLE)

rhyme: rhyme.o 
	$(CC) $(CFLAGS) -o rhyme rhyme.o

rhyme.o: rhyme.cpp rhyme.h
	$(CC) $(CFLAGS) -c rhyme.cpp

test_rhyme.o: test_rhyme.cpp rhyme.h
	$(CC) $(CFLAGS) -c test_rhyme.cpp
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(PERF_FILE)
	rm -Rf *.dSYM

.PHONY: all release debug profile clean
.SUFFIXES: