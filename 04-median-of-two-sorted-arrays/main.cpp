#include <iostream>

using namespace std;

/**
 * 4. 寻找两个正序数组的中位数
 * @param nums1 给定的正序数组
 * @param nums2 给定的正序数组
 * @return
 */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int N = nums1.size() + nums2.size();
    vector<int> data(N, 0);

    int k = 0;
    int m = 0, n = 0;

    while (m < nums1.size() && n < nums2.size()) {
        data[k++] = nums1[m] > nums2[n] ? nums2[n++] : nums1[m++]; // 将两个数组按正序排序  复杂度 O(log(m+n))
    }

    // 当长度小的数组全部进新数组时，剩下数组元素进新数组
    while (m < nums1.size()) data[k++] = nums1[m++];
    while (n < nums2.size()) data[k++] = nums2[n++];

    if (N % 2 == 0) {
        return (data[N / 2 - 1] + data[N / 2]) / 2.0;
    } else {
        return data[N / 2];
    }
}

int main() {
    return 0;
}
