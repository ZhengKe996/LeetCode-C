#include <iostream>

using namespace std;

int find(vector<int> &nums, int left, int right, int target) {
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return nums[left] == target ? left : -1;
}

/**
 * 33. 搜索旋转排序数组
 * @param nums
 * @param target
 * @return
 */
int search(vector<int> &nums, int target) {
    int N = nums.size();
    int idx = 0;

    for (int i = 0; i < N; i++) {
        if (nums[i] > nums[i + 1]) {
            idx = i; // 对数组进行遍历，找到旋转点
            break;
        }
    }
    int ans = find(nums, 0, idx, target);
    if (ans != -1)return ans; // 在左半段找到，直接返回

    if (idx + 1 < N) ans = find(nums, idx + 1, N - 1, target); // 左半段没找到的情况下 在右半段进行查找
    return ans;
}

/**
 * 33. 搜索旋转排序数组(二分)
 * @param nums
 * @param target
 * @return
 */
int search2(vector<int> &nums, int target) {
    int N = nums.size();
    int l = 0, r = N - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (nums[mid] >= nums[0]) l = mid;
        else r = mid - 1;
    }

    if (target >= nums[0]) l = 0;
    else {
        l++;
        r = N - 1;
    }

    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return (nums[r] == target ? r : -1);
}

int main() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int ans = search(nums, 0);
    printf("%d\n", ans);
    nums = {4, 5, 6, 7, 0, 1, 2};
    ans = search(nums, -1);
    printf("%d\n", ans);
    nums = {1};
    ans = search(nums, 1);
    printf("%d\n", ans);
    return 0;
}
