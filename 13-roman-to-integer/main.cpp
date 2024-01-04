#include <stdio.h>
#include<string.h>

int romanToInt(char *s) {
    int Values[26];
    Values['I' - 'A'] = 1;
    Values['V' - 'A'] = 5;
    Values['X' - 'A'] = 10;
    Values['L' - 'A'] = 50;
    Values['C' - 'A'] = 100;
    Values['D' - 'A'] = 500;
    Values['M' - 'A'] = 1000;

    int ans = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        int value = Values[s[i] - 'A'];
        if (i < n - 1 && value < Values[s[i + 1] - 'A']) {
            ans -= value;
        } else {
            ans += value;
        }
    }
    return ans;
}

int main() {
    return 0;
}
