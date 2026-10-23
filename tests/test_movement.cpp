#include "../domain/movement.h"
#include <cassert>
int main() {
    int board[20][20];
    for (auto& row : board) for (int& cell : row) cell = 1;
    board[10][10] = 0;
    assert(chooseDirection(board, 10, 10, 1, 0) == 0);
    board[11][10] = 0;
    assert(chooseDirection(board, 10, 10, 1, 42) == 2); // reverse out of dead end
    board[10][11] = 0;
    for (unsigned seed = 0; seed < 100; ++seed) assert(chooseDirection(board, 10, 10, 1, seed) == 3);
    board[0][0] = 0;
    assert(chooseDirection(board, 0, 0, 0, 0) == 0);
    assert(chooseDirection(board, -1, 0, 0, 0) == 0);
}
