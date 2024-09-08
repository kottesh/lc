#include <bits/stdc++.h>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num; 
        }       
        return res;
    }
};

int main() {
    std::vector<int> a {2, 2, 1};
    std::cout << (new Solution())->singleNumber(a);
    return 0;
}
