#include <iostream>

using namespace std;

void dfs(vector<int> &candidates, int start, int len, int target, vector<int> &path, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(path);
        return;
    }

    for (int i = start; i < len && target - candidates[i] >= 0; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // 重复数不进行操作

        path.push_back(candidates[i]);
        dfs(candidates, i + 1, len, target - candidates[i], path, res);
        path.pop_back();
    }

}

/**
 * 40. 组合总和 II
 * @param candidates
 * @param target
 * @return
 */
vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    int N = candidates.size();
    vector<vector<int>> res;
    vector<int> path;

    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, N, target, path, res);
    return res;
}

int main() {
    return 0;
}
