#include <iostream>

using namespace std;

/**
 * 两数之和(双指针)
 * @param nums
 * @param start
 * @param target
 * @return
 */
vector<vector<int>> twoSum(vector<int> &nums, int start, long target) {
    vector<vector<int>> ans;
    int N = nums.size();
    int j = N - 1;

    for (int i = start; i < N; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue; // 去重
        while (i < j && (long) nums[i] + nums[j] > target) {
            j--;
        }
        if (i < j && nums[i] + nums[j] == target) {
            ans.push_back({nums[i], nums[j]});
        }
    }
    return ans;
}


/**
 * 18. 四数之和(双指针)
 * @param nums
 * @param target
 * @return
 */
vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());// 将数组排序
    vector<vector<int>> ans;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        if (nums[i] > 0 && nums[i] > target)return ans; // nums[i] > target 直接返回 剪枝
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
        for (int j = i + 1; j < N; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            vector<vector<int>> temps = twoSum(nums, j + 1, (long) target - nums[i] - nums[j]);
            for (vector<int> temp: temps) {
                ans.push_back({nums[i], nums[j], temp[0], temp[1]});
            }
        }
    }
    return ans;
}


int main() {
    vector<int> nums = {-1000000000, -1000000000, 1000000000, -1000000000, -1000000000};
    vector<vector<int>> res = fourSum(nums, 294967296);

    for (vector<int> item: res) {
        for (int i: item) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
