#include <iostream>

using namespace std;

/**
 * 16. 最接近的三数之和(双指针)
 * @param nums
 * @param target
 * @return
 */
int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int result = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size() - 2; i++) {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left != right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(result - target)) {
                result = sum;
            }
            if (sum > target)right--;
            else left++;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int result = threeSumClosest(nums, 1);
    printf("%d", result);
    return 0;
}
