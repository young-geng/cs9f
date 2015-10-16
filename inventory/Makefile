SHELL := /bin/bash
CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

EXECUTABLE := p3.1

TEST_IN_FILE := test/TEST_NAME.in.txt
TEST_OUT_FILE := test/TEST_NAME.out.txt
TEST_COMMAND := test -z "`./$(EXECUTABLE) < $(TEST_IN_FILE) 2>&1 | diff $(TEST_OUT_FILE) -`"


all: p3.1


inventory.o: inventory.h inventory.cpp
	@$(CXX) $(CXXFLAGS) -c inventory.cpp


p3.1.o: p3.1.cpp
	@$(CXX) $(CXXFLAGS) -c p3.1.cpp

$(EXECUTABLE): p3.1.o inventory.o
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) p3.1.o inventory.o


test_blank: p3.1 $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'

test_wrong_command: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'

test_batch: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'

test_inventory: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'


check: test_blank test_wrong_command test_batch test_inventory
	@echo "All test passed!"

clean:
	@rm -rf p3.1.o $(EXECUTABLE) inventory.o

.PHONY: all clean check test_blank test_wrong_command test_batch test_inventory
