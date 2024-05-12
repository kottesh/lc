#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> ans;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0 ; j < nums.size(); j++) {
                if (i == j) continue;
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    found = true;
                }
            }
            if (found) break;
        }
        return ans;
    }
};

int main() {
    (new Solution())->twoSum({2, 7,11,15}, 9);
    return 0;
} 
