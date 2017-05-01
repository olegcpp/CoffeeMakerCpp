src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
CXX=g++
CC=g++
CXXFLAGS=-std=c++14 -Wall -I/Users/oleg/prog/cpputest_inst/cpputest/include
LDFLAGS = -L/Users/oleg/prog/cpputest_inst/cpputest/lib -lCppUTest

.PHONY: all
all: coffeeMaker

coffeeMaker: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)
	
.PHONY:clean
clean:
	rm *.o coffeeMaker