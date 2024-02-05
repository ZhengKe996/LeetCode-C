#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 49. 字母异位词分组
 * 创建一个哈希表，遍历strs，将遍历得到的每个字符串排序，再遍历一遍哈希表，将哈希表中的vector添加进答案中
 * @param strs
 * @return
 */
vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> groups;
    for (string &str: strs) {
        string copy = str;
        sort(copy.begin(), copy.end());
        if (groups.find(copy) == groups.end()) {
            groups[copy] = {};
        }
        groups[copy].push_back(str);
    }
    vector<vector<string >> ans;
    for (const pair<string, vector<string>> &group: groups) {
        ans.push_back(group.second);
    }
    return ans;
}

int main() {
    return 0;
}
