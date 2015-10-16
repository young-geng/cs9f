SHELL := /bin/bash
CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

EXECUTABLE := amoebamain

TEST_IN_FILE := test/TEST_NAME.in.txt
TEST_OUT_FILE := test/TEST_NAME.out.txt
TEST_COMMAND := test -z "`./$(EXECUTABLE) < $(TEST_IN_FILE) 2>&1 | diff $(TEST_OUT_FILE) -`"


all: $(EXECUTABLE)

amoebas.o: amoebas.cpp amoebas.h
	@$(CXX) $(CXXFLAGS) -c amoebas.cpp

amoebamain.o: amoebamain.cpp
	@$(CXX) $(CXXFLAGS) -c amoebamain.cpp

$(EXECUTABLE): amoebas.o amoebamain.o
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) amoebas.o amoebamain.o


clean:
	@rm -rf $(EXECUTABLE) amoebamain.o amoebas.o