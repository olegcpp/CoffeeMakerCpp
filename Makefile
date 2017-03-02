src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
CXX=g++
CC=g++
CXXFLAGS=-std=c++14 -Wall

LDFLAGS = -lCppUTest

.PHONY: all
all: coffeeMaker

coffeeMaker: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)
	
.PHONY:clean
clean:
	rm *.o coffeeMaker