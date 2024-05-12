#include <bits/stdc++.h>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows == 1)
            return s;
        std::vector<std::vector<char>> store(numRows);

        int row = 0;
        bool linear = true;
        for (char c:s) {
            if (linear) {
                if (row != numRows-1)
                    store[row++].push_back(c);
                if (row == numRows-1)
                    linear = false;
            } else {
                if (row != 0)
                    store[row--].push_back(c);
                if (row == 0)
                    linear = true;
            }
        }

        std::string res;
        for (const auto& row:store) {
            for (char c:row) {
                res += c;
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    std::cout << sol.convert("A", 3);
}