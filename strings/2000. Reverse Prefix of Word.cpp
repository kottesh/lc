#include <bits/stdc++.h>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                std::reverse(word.begin(), word.begin() + i +1);
                break;
            }
            if (i == word.size() -1) return word;
        }
        return word;
    }
};

int main () {
    Solution sol;
    std::cout << sol.reversePrefix("xyxzxe", 'z');
}