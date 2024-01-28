#include <iostream>

using namespace std;

void backtrack(vector<int> &nums, vector<vector<int>> &ans, int idx, vector<int> &perm, vector<int> vis) {
    if (idx == nums.size()) {
        ans.emplace_back(perm);
        return;
    }
    for (int i = 0; i < (int) nums.size(); ++i) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
            continue;
        }
        perm.emplace_back(nums[i]);
        vis[i] = 1;
        backtrack(nums, ans, idx + 1, perm, vis);
        vis[i] = 0;
        perm.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> perm;
    vector<int> vis;
    vis.resize(nums.size());
    sort(nums.begin(), nums.end());
    backtrack(nums, ans, 0, perm, vis);
    return ans;
}

int main() {
    return 0;
}
