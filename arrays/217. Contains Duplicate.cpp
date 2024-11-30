#include <bits/stdc++.h>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // std::unordered_map<int, int> map;

        // for (const int& num : nums) {
        //     map[num]++;
        //     if (map[num] > 1)
        //         return true;
        // }

        // return false;
        std::sort(nums.begin(), nums.end());

        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i]) return true;
            prev = nums[i];
        }

        return false;
    }
};

int main() {
    std::vector<int> nums {1, 2, 3, 1};

    std::cout << (new Solution())->containsDuplicate(nums);
}

