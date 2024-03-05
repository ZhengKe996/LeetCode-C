#include <iostream>
#include <stack>

using namespace std;

/**
 * 前缀和+单调栈
 * @param matrix
 * @return
 */
int maximalRectangle(vector<vector<char>> &matrix) {
    int N = matrix.size(), M = matrix[0].size();
    vector<int> heights(M + 1, 0);// 多一列方便将单调栈最后一个有效元素弹出
    int maxArea = 0; // 计算最大面积

    for (int row = 0; row < N; row++) {
        stack<int> stk;// 每一行都按一个独立的单调栈去处理
        for (int col = 0; col <= M; col++) {
            if (col < M && matrix[row][col] == '1')
                heights[col] += 1;
            else
                heights[col] = 0; // 本行的此列直接置为0 而不是保持height不变；


            // 单调栈模版:当前元素比栈顶元素小就处理
            while (!stk.empty() && heights[col] < heights[stk.top()]) {
                int height = heights[stk.top()]; //可以对top元素计算面积，因为知道了它的左边比他低的，右边比他低的元素
                stk.pop();
                int leftLessMin = stk.empty() ? -1 : stk.top(); //左侧比栈顶元素小的，是当前栈里的顶元素
                int RightLessMin = col; //右侧比栈顶元素小的，肯定是当前元素
                int area = (RightLessMin - leftLessMin - 1) * height;
                maxArea = max(area, maxArea);
            }
            stk.push(col);

        }
    }
    return maxArea;
}

int main() {
    return 0;
}
