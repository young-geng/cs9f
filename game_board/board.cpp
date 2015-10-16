#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <array>

#include "board.h"

using namespace std;


template<size_t BoardSize>
Board<BoardSize>::Board() {
    for (auto iter = board.begin(); iter != board.end(); iter++) {
        iter->fill('.');
    }
}

template<size_t BoardSize>
void Board<BoardSize>::SetCell(int player, int row, int col, char c) {
    if (row < 0 || row >= BoardSize || col < 0 || col >= BoardSize || player < 0 || player > 1)
        return;
    GetCell(player, row, col) = c;
}

template<size_t BoardSize>
char& Board<BoardSize>::GetCell(int player, int row, int col) {
    if (player == 1) {
        row = BoardSize - row - 1;
        col = BoardSize - col - 1;
    }
    return board[row][col];
}

template<size_t BoardSize>
void Board<BoardSize>::Print(int player) {
    if (player < 0 || player > 1)
        return;
    for (int i = 0; i < BoardSize; i++) {
        for (int j = 0; j < BoardSize; j++) {
            cout << GetCell(player, i, j);
        }
        cout << endl;
    }
    cout << endl;
}



int main(int argc, char *argv[]) {
    bool prompt = false;
    if (argc == 2 && string(argv[1]) == "-p")
        prompt = true;

    Board<5> board;

    string line, lineInWord;
    int player, row, col;
    char c;
    while (!cin.eof()) {
        if (prompt)
            cout << ">>> ";
        getline(cin, line);
        istringstream lineIn (line);
        lineIn >> lineInWord;
        if (lineIn.fail()) {
          cout << "Read input failed!" ;
        } else if (lineInWord == "set") {
            lineIn >> player >> row >> col >> c;
            if (lineIn.fail()) {
                cout << "Wrong command!" << endl;
                continue;
            }
            board.SetCell(player, row, col, c);
        } else if (lineInWord == "print") {
            lineIn >> player;
            if (lineIn.fail()) {
                cout << "Wrong command!" << endl;
                continue;
            }
            board.Print(player);

        } else if (lineInWord == "quit") {
            exit(0);
        } else { 
            cout << "Unrecognizable command word." << endl; 
        }
    }
}