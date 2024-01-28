#include <iostream>

using namespace std;

/**
 * 45. 跳跃游戏 II
 * @param nums
 * @return
 */
int jump(vector<int> &nums) {
    int now = 0, ans = 0;
    int N = nums.size();
    while (now < N - 1) {
        int right = now + nums[now];
        if (right >= N - 1)return ans + 1;
        int nextRight = right, next = now;
        for (int i = now + 1; i <= right; i++) {
            if (i + nums[i] > nextRight) {
                nextRight = i + nums[i];
                next = i;
            }
        }
        now = next;
        ans++;
    }
    return ans;
}

int main() {
    return 0;
}
