#include <iostream>

using namespace std;

/**
 * 26. 删除有序数组中的重复项
 * @param nums
 * @return
 */
int removeDuplicates(vector<int> &nums) {
    int n = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            nums[n] = nums[i];
            n++;
        }
    }
    return n;
}

int main() {
    return 0;
}
