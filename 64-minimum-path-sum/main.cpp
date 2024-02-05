#include <iostream>

using namespace std;

/**
 * 64. 最小路径和(DP)
 * @param grid
 * @return
 */
int minPathSum(vector<vector<int>> &grid) {
    int N = grid.size(), M = grid[0].size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0)continue;
            else if (i == 0) grid[i][j] = grid[i][j - 1] + grid[i][j];
            else if (j == 0) grid[i][j] = grid[i - 1][j] + grid[i][j];
            else grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
    }
    return grid[N - 1][M - 1];
}

int main() {
    return 0;
}
