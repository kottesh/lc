#include <bits/stdc++.h>

class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            if (i > maxIndex) return false;
            maxIndex = std::max(maxIndex, i + nums[i]);
        }
        return true;
    }
};

int main() {
    std::cout << (new Solution())->canJump(std::vector<int> {5,9,3,2,1,0,2,3,3,1,0,0});
}
