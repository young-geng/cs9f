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
    lineIn >> lineInWord;
    if ( lineIn.fail() ) {
      cerr << "Read line failed!" ;
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

void InterpretUpdate (istream&) {
  cout << "Command get!" << endl;
}
void InterpretList (istream&) {
  cout << "Command get!" << endl;
}
void InterpretBatch (istream&) {
  cout << "Command get!" << endl;
}
void InterpretQuit (istream&) {
  cout << "Command get!" << endl;
}

int main ( ) {
  InterpretCommands (cin);
  return 0;
}
