CXX := g++
CXXFLAGS := -std=c++11 -g

EXECUTABLE := sltest

TEST_IN_FILE := test/TEST_NAME.in.txt
TEST_OUT_FILE := test/TEST_NAME.out.txt
TEST_COMMAND := test -z "`./$(EXECUTABLE) < $(TEST_IN_FILE) 2>&1 | diff $(TEST_OUT_FILE) -`"


all: $(EXECUTABLE)


sltest.o: sltest.cpp sorted.lists.h
	@$(CXX) $(CXXFLAGS) -c sltest.cpp

$(EXECUTABLE): sltest.o
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) sltest.o

clean:
	@rm -rf sltest sltest.o

test1: $(EXECUTABLE) $(subst, TEST_NAME, $@, $(TEST_IN_FILE)) $(subst, TEST_NAME, $@, $(TEST_OUT_FILE))
	@$(subst TEST_NAME,$@,$(TEST_COMMAND))
	@echo '$@ passed'


check: test1
	@echo 'All test passed!'

.PHONY: clean all check test1
