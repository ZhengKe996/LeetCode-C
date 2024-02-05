#include <iostream>
#include <queue>

using namespace std;

/**
 * 75. 颜色分类
 * @param nums
 */
void sortColors(vector<int> &nums) {
    int N = nums.size();
    if (nums.empty() || N < 2)return;

    int zero = 0;
    int two = N;
    int i = 0;
    while (i < two) {
        if (nums[i] == 0) {
            swap(nums[zero], nums[i]);
            zero++;
            i++;
        } else if (nums[i] == 1) {
            i++;
        } else {
            two--;
            swap(nums[i], nums[two]);
        }
    }

}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}
