#include <stdio.h>
#include<stdlib.h>
#include <unordered_map>

using namespace std;


/**
 * 解法一：双重For循环暴力解 时间复杂度O(N^2)
 * @param nums
 * @param numsSize
 * @param target
 * @param returnSize
 * @return
 */
int *twoSum1(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *result = (int *) malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}


vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); i++) {
        auto item = hashtable.find(target - nums[i]);
        if (item != hashtable.end()) return {item->second, i};

        hashtable[nums[i]] = i;
    }
    return {};
}

int main() {
    return 0;
}
