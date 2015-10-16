SHELL := /bin/bash
CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

EXECUTABLE := selection

TEST_IN_FILE := test/TEST_NAME.in.txt
TEST_OUT_FILE := test/TEST_NAME.out.txt
TEST_COMMAND := test -z "`./$(EXECUTABLE) < $(TEST_IN_FILE) 2>&1 | diff $(TEST_OUT_FILE) -`"


all: $(EXECUTABLE)


dll.o: dll.cpp dll.h
	@$(CXX) $(CXXFLAGS) -c dll.cpp

selection.o: selection.cpp
	@$(CXX) $(CXXFLAGS) -c selection.cpp

$(EXECUTABLE): dll.o selection.o
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) dll.o selection.o



clean:
	@rm -rf $(EXECUTABLE) dll.o selection.o