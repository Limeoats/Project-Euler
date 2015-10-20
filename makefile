CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic -lstdc++ -fno-exceptions
BIN=projecteuler

SRC=$(wildcard *.cc)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)
