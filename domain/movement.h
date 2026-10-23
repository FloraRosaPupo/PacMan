#ifndef PACMAN_MOVEMENT_H
#define PACMAN_MOVEMENT_H
#include <array>
// Directions: 1 up, 2 down, 3 right, 4 left; 0 means no legal move.
inline int chooseDirection(const int board[20][20], int x, int y, int previous, unsigned randomValue) {
    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {-1, 1, 0, 0};
    const int opposite[] = {0, 2, 1, 4, 3};
    std::array<int, 4> legal{};
    unsigned count = 0;
    if (x < 0 || x >= 20 || y < 0 || y >= 20) return 0;
    for (int direction = 1; direction <= 4; ++direction) {
        const int nx = x + dx[direction - 1], ny = y + dy[direction - 1];
        if (nx < 0 || nx >= 20 || ny < 0 || ny >= 20 || board[ny][nx] == 1) continue;
        legal[count++] = direction;
    }
    if (count == 0) return 0;
    std::array<int, 4> forward{};
    unsigned forwardCount = 0;
    for (unsigned i = 0; i < count; ++i) {
        if (previous < 1 || previous > 4 || legal[i] != opposite[previous]) forward[forwardCount++] = legal[i];
    }
    // A dead end permits reversing; never spin indefinitely waiting for a direction.
    return forwardCount ? forward[randomValue % forwardCount] : legal[randomValue % count];
}
#endif
