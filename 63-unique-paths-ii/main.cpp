#include <iostream>

using namespace std;

/**
 * 63. 不同路径 II
 * @param obstacleGrid
 * @return
 */
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int N = obstacleGrid.size(), M = obstacleGrid[0].size();
    vector<int> f(M, 0);
    f[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (obstacleGrid[i][j] == 1) {
                f[j] = 0;
                continue;
            }
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) f[j] += f[j - 1];
        }
    }
    return f.back();
}

int main() {
    return 0;
}
