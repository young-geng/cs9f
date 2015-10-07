CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

all: cat+mouse

positions.o: positions.cpp positions.h
	$(CXX) $(CXXFLAGS) -c positions.cpp

cat+moust.o: cat+mouse.cpp
	$(CXX) $(CXXFLAGS) -c cat+mouse.cpp

cat+mouse: cat+mouse.o positions.o
	$(CXX) $(CXXFLAGS) -o cat+mouse cat+mouse.o positions.o

clean:
	rm -f positions.o cat+mouse.o cat+mouse

test1: cat+mouse test1.in
	./cat+mouse < test1.in

test2: cat+mouse test2.in
	./cat+mouse < test2.in

.PHONY: all clean test1 test2

