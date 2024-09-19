#include <bits/stdc++.h>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> store;
        
        int start = 0, i = 0;

        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') i++;
            start = i;

            while (i < s.length() && s[i] != ' ') i++;
            if (start < i) {
                store.push_back(s.substr(start, i - start));
            }
        }

        std::reverse(store.begin(), store.end());

        std::string res;
        for (int i = 0; i < store.size(); i++) {
            res += store[i];
            if (i != store.size() - 1) {
                res += ' ';
            }
        }

        return res;
    }
};

int main() {
    std::cout << (new Solution())->reverseWords("  hello world  ");
    return 0;
}
