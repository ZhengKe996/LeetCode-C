#include <iostream>

using namespace std;

/**
 * 59. 螺旋矩阵 II
 * @param n
 * @return
 */
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;

    int num = 1, tar = n * n;

    while (num <= tar) {
        for (int i = left; i <= right; i++) ans[top][i] = num++;
        top++;

        for (int i = top; i <= bottom; i++) ans[i][right] = num++;
        right--;

        for (int i = right; i >= left; i--)ans[bottom][i] = num++;
        bottom--;

        for (int i = bottom; i >= top; i--)ans[i][left] = num++;
        left++;
    }
    return ans;
}

int main() {
    return 0;
}
