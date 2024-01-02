#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x) {

    if (x < 0)return false;

    long x1 = x, y = 0l; // x1 被操作，y用来暂存每一次操作的结果
    while (x1) {
        y = y * 10 + x1 % 10;
        x1 /= 10;
    }
    return x == y;
}

int main() {
    return 0;
}
