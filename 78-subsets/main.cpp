#include <iostream>

using namespace std;

void recur(vector<int> &nums, int i, int N, vector<vector<int>> &ans, vector<int> &chosen) {
    if (i == N) {
        ans.push_back(chosen);
        return;
    }
    recur(nums, i + 1, N, ans, chosen);
    chosen.push_back(nums[i]);
    recur(nums, i + 1, N, ans, chosen);
    chosen.pop_back();
}


/**
 * 78. 子集(回溯)
 * @param nums
 * @return
 */
vector<vector<int>> subsets(vector<int> &nums) {
    int N = nums.size();
    vector<vector<int>> ans;
    vector<int> chosen;

    recur(nums, 0, N, ans, chosen);
    return ans;
}

int main() {
    return 0;
}
