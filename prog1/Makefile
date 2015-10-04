CXX := g++
CXXFLAGS := -std=c++11 -g



adding_machine: adding_machine.cpp
	$(CXX) $(CXXFLAGS) -o adding_machine adding_machine.cpp
	@rm -rf adding_machine.dSYM

clean:
	rm -rf adding_machine adding_machine.dSYM

.PHONY: clean
