#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

#include "inventory.h"

using namespace std;

Inventory inventory;

void InterpretCommands (istream&, bool);
void InterpretUpdate (istream&);
void InterpretList (istream&);
void InterpretBatch (istream&);
void InterpretQuit (istream&);

void InterpretCommands (istream& cmds, bool allow_batch=true) {
  string line, lineInWord;
  while (!getline(cmds, line).eof()) {
    istringstream lineIn (line);
    lineIn >> lineInWord;
    if ( lineIn.fail() ) {
      cerr << "Read line failed!" ;
    } else if (lineInWord == "update") {
      InterpretUpdate (lineIn);
    } else if (lineInWord == "list") {
      InterpretList (lineIn);
    } else if (lineInWord == "batch" && allow_batch) {
      InterpretBatch (lineIn);
    } else if (lineInWord == "quit") {
      InterpretQuit (lineIn);
    } else { 
      cerr << "Unrecognizable command word." << endl; 
    }
  }
}

void InterpretUpdate (istream& lineIn) {
  string name;
  int number;
  lineIn >> name;
  if (lineIn.fail()) {
    cerr << "Unrecognizable command args." << endl; 
    return;
  }
  lineIn >> number;
  if (lineIn.fail() || !lineIn.eof()) {
    cerr << "Unrecognizable command args." << endl; 
    return;
  }
  inventory.Update(name, number);
}
void InterpretList (istream& lineIn) {
  string target;
  lineIn >> target;
  if (lineIn.fail() || (target != "names" && target != "quantities") || !lineIn.eof()) {
    cerr << "Unrecognizable command args." << endl; 
    return;
  }
  if (target == "names") {
    auto v = inventory.ListByName();
    for (auto iter = v.begin(); iter != v.end(); iter++) {
      cout << iter->first << " :  " << iter->second << endl;
    }
  } else {
    auto v = inventory.ListByQuantity();
    for (auto iter = v.begin(); iter != v.end(); iter++) {
      cout << iter->first << " :  " << iter->second << endl;
    }
  }
}
void InterpretBatch (istream& lineIn) {
  string filename;
  lineIn >> filename;
  if (lineIn.fail() || !lineIn.eof()) {
    cerr << "Unrecognizable command args." << endl; 
    return;
  }
  fstream fin(filename, ios::in);
  if (!fin.is_open()) {
    cerr << "File does not exist!" << endl; 
    return;
  }
  InterpretCommands(fin, false);
}
void InterpretQuit (istream& lineIn) {
  if (!lineIn.eof()) {
    cerr << "Unrecognizable command args." << endl;
    return;
  }
  exit(0);
}

int main ( ) {
  InterpretCommands (cin);
  return 0;
}
