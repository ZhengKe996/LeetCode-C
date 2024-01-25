#include <iostream>

using namespace std;

/**
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 * @param nums
 * @param target
 * @return
 */
vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans;
    int N = nums.size();
    int l = 0, r = N;

    while (l < r) {
        int mid = l + ((r - l) >> 1);
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }

    ans.push_back(r);// 查找到元素的第一个位置

    l = -1;
    r = N - 1;
    while (l < r) {
        int mid = l + ((r - l + 1) >> 1);
        if (nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    ans.push_back(r);

    if (ans[0] > ans[1]) return {-1, -1};
    else return ans;
}

int main() {
    return 0;
}
