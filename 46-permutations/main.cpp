#include <iostream>

using namespace std;

void recur(vector<int> &nums, int pos, int N, vector<int> &a, vector<bool> &used, vector<vector<int>> &ans) {
    if (pos == N) {
        ans.push_back(a);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            a.push_back(nums[i]);
            used[i] = true;
            recur(nums, pos + 1, N, a, used, ans);
            used[i] = false;
            a.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    int N = nums.size();
    vector<bool> used(N, false);
    vector<vector<int>> ans;
    vector<int> a;
    recur(nums, 0, N, a, used, ans);
    return ans;
}

int main() {
    return 0;
}
