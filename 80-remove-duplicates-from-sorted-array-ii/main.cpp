#include <iostream>

using namespace std;

int process(vector<int> &nums, int k) {
    int i = 0;
    for (int num: nums) {
        if (i < k || nums[i - k] != num)nums[i++] = num;
    }
    return i;
}

/**
 * 80. 删除有序数组中的重复项 II
 * @param nums
 * @return
 */
int removeDuplicates(vector<int> &nums) {
    return process(nums, 2);
}

int main() {
    return 0;
}
