#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <array>


template<size_t BoardSize>
class Board {
 public:
    Board();
    void SetCell(int player, int row, int col, char c);
    void Print(int player);

 private:
    std::array<std::array<char, BoardSize>, BoardSize> board;
    char& GetCell(int player, int row, int col);
};


#endif
