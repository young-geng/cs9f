#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void InterpretCommands (istream&);
void InterpretUpdate (istream&);
void InterpretList (istream&);
void InterpretBatch (istream&);
void InterpretQuit (istream&);

void InterpretCommands (istream& cmds) {
  string line, lineInWord;
  while (!getline(cin, line).eof()) {
    istringstream lineIn (line);
    if ( ________ ) {
      ________ ;
    } else if (lineInWord == "update") {
      InterpretUpdate (lineIn);
    } else if (lineInWord == "list") {
      InterpretList (lineIn);
    } else if (lineInWord == "batch") {
      InterpretBatch (lineIn);
    } else if (lineInWord == "quit") {
      InterpretQuit (lineIn);
    } else { 
      cerr << "Unrecognizable command word." << endl; 
    }
  }
}

int main ( ) {
  InterpretCommands (cin);
  return 0;
}
