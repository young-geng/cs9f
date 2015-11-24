CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

all: cat+mouse


park.o: park.cpp park.h positions.h
	@$(CXX) $(CXXFLAGS) -c park.cpp

animals.o: animals.cpp animals.h positions.h
	@$(CXX) $(CXXFLAGS) -c animals.cpp

positions.o: positions.cpp positions.h
	@$(CXX) $(CXXFLAGS) -c positions.cpp

cat+mouse.o: cat+mouse.cpp
	@$(CXX) $(CXXFLAGS) -c cat+mouse.cpp

cat+mouse: cat+mouse.o positions.o park.o animals.o
	@$(CXX) $(CXXFLAGS) -o cat+mouse cat+mouse.o positions.o park.o animals.o

clean:
	@rm -f positions.o cat+mouse.o park.o animals.o cat+mouse


test1: cat+mouse test/test1.in.txt test/test1.out.txt
	@test -z "`./cat+mouse -q < test/test1.in.txt | diff test/test1.out.txt -`"
	@echo 'test 1 passed'


check: test1
	@echo 'All test passed!'

.PHONY: all clean check test1

