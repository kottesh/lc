#include <bits/stdc++.h>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Bruteforce approach
        int min_len = INT_MAX;

        std::string res = "";

        for (const auto& str : strs) {
            min_len = std::min(min_len, (int)str.length());
        }    
        
        std::string arb_str = strs[0];
        for (int i = 0; i < min_len; i++) {
            for (const auto& str : strs) {
                if (str[i] != arb_str[i])
                    return res;
            }
            res += arb_str[i];
        }
        return res;
    }
};

int main() {
    std::vector<std::string> strs {"flower","flow","flight"};
    std::cout << (new Solution())->longestCommonPrefix(strs) << "\n";
}
