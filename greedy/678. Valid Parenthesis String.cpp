#include <bits/stdc++.h>

class Solution {
    bool isValid(const std::string &s, std::vector<std::vector<int>>& dp, int count = 0, int idx = 0) {
        if (count < 0)
            return false;

        if (idx == s.size())
            return count == 0;

        if (dp[idx][count] != -1)
            return dp[idx][count];
        
        bool res;
        if (s[idx] == '(')
            res = isValid(s, dp, count + 1, idx + 1);
        else if (s [idx] == ')')
            res = isValid(s, dp, count - 1, idx + 1);
        else
            res = isValid(s, dp, count + 1, idx + 1) or isValid(s, dp, count - 1, idx + 1) or isValid(s, dp, count, idx + 1);

        return dp[idx][count] = res;
    }
public:
    bool checkValidString(std::string s) {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size() + 1, -1)); 

        return isValid(s, dp);
    }
};

int main() {
    std::cout << (new Solution())->checkValidString("(*)");
}

