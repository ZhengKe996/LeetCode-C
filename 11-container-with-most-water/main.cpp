#include <iostream>

using namespace std;

/**
 * 11. 盛最多水的容器
 * @param height 给定的高度数组
 * @return
 */
int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1, ans = 0;
    while (i < j) {
        ans = max(ans, min(height[i], height[j]) * (j - i)); // 取 i与j 位置的最小值为高 乘以长(j-i) 并与暂存结果相比取max
        if (height[i] <= height[j]) {  // 如果 i位置的高比j位置的高小 则i++ 反之 j-- 直到 i=j
            i++;
        } else {
            j--;
        }
    }
    return ans; // 循环结束保证了ans暂存的永远都是max值
}

int main() {
    return 0;
}
