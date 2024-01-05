#include <stdio.h>
#include <string.h>


/**
 * 把第一个字符先拿出来（循环1），然后依次用用数值的相应字符与其比较（循环2）,然后判断是否相同，如果有一个字符不同则将这个字符赋'\0'，然后将新的数组赋给strs[0]，然后return 新的strs[0];
 * @param strs
 * @param strsSize
 * @return
 */
char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0)return "";

    for (int i = 0; i < strlen(strs[0]); i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[0][i] != strs[j][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}


