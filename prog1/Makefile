CXX := g++
CXXFLAGS := -std=c++11 -g


all: adding_machine


adding_machine.o: adding_machine.cpp
	@$(CXX) $(CXXFLAGS) -c adding_machine.cpp

adding_machine: adding_machine.o
	@$(CXX) $(CXXFLAGS) -o adding_machine adding_machine.o

clean:
	@rm -rf adding_machine adding_machine.o

check: adding_machine test/test.in.txt test/test.out.txt
	@test -z "`./adding_machine < test/test.in.txt | diff test/test.out.txt -)`"

.PHONY: clean all check
