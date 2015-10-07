CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

all: cat+mouse

positions.o: positions.cpp positions.h
	@$(CXX) $(CXXFLAGS) -c positions.cpp

cat+mouse.o: cat+mouse.cpp
	@$(CXX) $(CXXFLAGS) -c cat+mouse.cpp

cat+mouse: cat+mouse.o positions.o
	@$(CXX) $(CXXFLAGS) -o cat+mouse cat+mouse.o positions.o

clean:
	@rm -f positions.o cat+mouse.o cat+mouse


test1: cat+mouse test/test1.in.txt test/test1.out.txt
	@test -z "`./cat+mouse -q < test/test1.in.txt | diff test/test1.out.txt -`"

test2: cat+mouse test/test2.in.txt test/test2.out.txt
	@test -z "`./cat+mouse -q < test/test2.in.txt | diff test/test2.out.txt -`"


check: test1 test2

.PHONY: all clean check test1 test2

