SHELL := /bin/bash
CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

EXECUTABLE := destr_test

TEST_IN_FILE := test/TEST_NAME.in.txt
TEST_OUT_FILE := test/TEST_NAME.out.txt
TEST_COMMAND := test -z "`./$(EXECUTABLE) < $(TEST_IN_FILE) 2>&1 | diff $(TEST_OUT_FILE) -`"


all: $(EXECUTABLE)

lists.o: lists.cpp lists.h
	@$(CXX) $(CXXFLAGS) -c lists.cpp

destr.test.o: destr.test.cpp
	@$(CXX) $(CXXFLAGS) -c destr.test.cpp

$(EXECUTABLE): lists.o destr.test.o
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) lists.o destr.test.o

test1: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'

test2: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'


check: test1 test2
	@echo 'All test passed!'


clean:
	@rm -rf $(EXECUTABLE) lists.o destr.test.o

.PHONY: all clean check test1 test2
