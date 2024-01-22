#include <iostream>

using namespace std;

/**
 * 两数之和(双指针)
 * @param nums
 * @param start
 * @param target
 * @return
 */
vector<vector<int>> twoSum(vector<int> &nums, int start, int target) {
    vector<vector<int>> ans;
    int N = nums.size();
    int j = N - 1;

    for (int i = start; i < N; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue; // 去重

        while (i < j && nums[i] + nums[j] > target) {
            j--;  // 双指针
        }

        if (i < j && nums[i] + nums[j] == target) {
            ans.push_back({nums[i], nums[j]});
        }
    }
    return ans;
}

/**
 *  15. 三数之和
 * @param nums
 * @return
 */
vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());// 将数组排序
    vector<vector<int>> ans;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重

        vector<vector<int>> temps = twoSum(nums, i + 1, -nums[i]);
        for (vector<int> temp: temps) {
            ans.push_back({nums[i], temp[0], temp[1]});
        }
    }
    return ans;
}


int main() {
    return 0;
}
