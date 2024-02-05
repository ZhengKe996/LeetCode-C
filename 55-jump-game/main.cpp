#include <iostream>

using namespace std;

/**
 * 55. 跳跃游戏（DP）
 * @param nums
 * @return
 */
bool canJump(vector<int> &nums) {
    int k = 0;// 初始化当前能到达最远的位置
    for (int i = 0; i < nums.size(); i++) {
        if (i > k)return false;
        k = max(k, i + nums[i]); // max(当前位置+跳数,最远位置)
    }
    return true;
}

int main() {
    return 0;
}
