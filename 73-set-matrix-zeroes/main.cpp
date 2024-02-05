#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * 73. 矩阵置零
 * 两遍扫matrix,第一遍用集合记录哪些行,哪些列有0;第二遍置0
 * @param matrix
 */
void setZeroes(vector<vector<int>> &matrix) {
    unordered_set<int> rows, cols;
    int row = matrix.size(), col = matrix[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((rows.find(i) != rows.end()) || (cols.find(j) != cols.end())) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    return 0;
}
