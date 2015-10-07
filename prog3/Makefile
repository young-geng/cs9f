CXX := g++
CXXFLAGS := -std=c++11 -g -Wall


all: p3.1


p3.1.o: p3.1.cpp
	@$(CXX) $(CXXFLAGS) -c p3.1.cpp

p3.1: p3.1.o
	@$(CXX) $(CXXFLAGS) -o p3.1 p3.1.o


clean:
	@rm -rf p3.1.o p3.1

.PHONY: all clean