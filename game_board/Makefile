SHELL := /bin/bash
CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

EXECUTABLE := board
TEST_IN_FILE := test/TEST_NAME.in.txt
TEST_OUT_FILE := test/TEST_NAME.out.txt
TEST_COMMAND := test -z "`./$(EXECUTABLE) < $(TEST_IN_FILE) 2>&1 | diff $(TEST_OUT_FILE) -`"


all: $(EXECUTABLE)

board.o: board.cpp board.h
	@$(CXX) $(CXXFLAGS) -c board.cpp

$(EXECUTABLE): board.o
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) board.o


test1: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'

test2: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'


check: test1 test2
	@echo 'All test passed!'

clean:
	@rm -rf board.o $(EXECUTABLE)

.PHONY: clean check test1 test2