#include <iostream>

using namespace std;

/**
 * 42. 接雨水(动态规划)
 * @param height
 * @return
 */
int trap(vector<int> &height) {
    int N = height.size();
    vector<int> preMax(N, 0);
    vector<int> sufMax(N, 0);
    preMax[0] = height[0];

    for (int i = 1; i < N; i++) {
        preMax[i] = max(preMax[i - 1], height[i]);
    }

    sufMax[N - 1] = height[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        sufMax[i] = max(sufMax[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        int up = min(preMax[i - 1], sufMax[i + 1]);
        int bottom = height[i];
        if (up > bottom) ans += (up - bottom);

    }
    return ans;
}

int main() {
    return 0;
}
