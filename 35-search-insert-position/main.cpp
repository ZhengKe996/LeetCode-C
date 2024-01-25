#include <iostream>

using namespace std;

/**
 * 35. 搜索插入位置(二分)
 * @param nums
 * @param target
 * @return
 */
int searchInsert(vector<int> &nums, int target) {
    int N = nums.size();
    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = l + (r - l >> 1);
        if (nums[mid] >= target) {
            r = mid - 1;
        } else l = mid + 1;
    }
    return l;
}

int main() {
    return 0;
}
