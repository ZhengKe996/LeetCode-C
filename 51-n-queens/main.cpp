#include <iostream>

using namespace std;

void dfs(int row, int n, vector<int> &p, vector<bool> &used, unordered_map<int, bool> &usedPlus,
         unordered_map<int, bool> &usedMinus, vector<vector<int>> &ans) {
    if (row == n) {
        ans.push_back(p);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (!used[col] && !usedPlus[row + col] && !usedMinus[row - col]) {
            p.push_back(col);
            used[col] = true;
            usedPlus[row + col] = true;
            usedMinus[row - col] = true;
            dfs(row + 1, n, p, used, usedPlus, usedMinus, ans);

            // 还原现场
            used[col] = false;
            usedPlus[row + col] = false;
            usedMinus[row - col] = false;
            p.pop_back();
        }
    }
}

/**
 * 51. N皇后(回溯)
 * @param n
 * @return
 */
vector<vector<string>> solveNQueens(int n) {
    vector<int> p;
    vector<bool> used;
    unordered_map<int, bool> usedPlus;
    unordered_map<int, bool> usedMinus;
    vector<vector<int>> ans;

    used = vector<bool>(n);
    vector<vector<string>> result;
    dfs(0, n, p, used, usedPlus, usedMinus, ans);
    for (vector<int> &p: ans) {
        vector<string> pattern(n, string(n, '.'));
        for (int row = 0; row < n; ++row) {
            pattern[row][p[row]] = 'Q';
        }
        result.push_back(pattern);
    }
    return result;
}

int main() {
    return 0;
}
