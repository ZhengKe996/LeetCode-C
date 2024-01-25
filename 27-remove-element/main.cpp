#include <iostream>

using namespace std;

/**
 * 27. 移除元素
 * @param nums
 * @param val
 * @return
 */
int removeElement(vector<int> &nums, int val) {
    int n = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[n] = nums[i];
            n++;
        }
    }
    return n;
}

int main() {
    return 0;
}
