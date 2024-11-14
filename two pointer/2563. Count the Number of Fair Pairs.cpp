#include <algorithm>
#include <bits/stdc++.h>
#include <ios>

typedef long long ll;

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::cin.tie(0); std::cout.tie(0);
        std::ios_base::sync_with_stdio(false);

        std::sort(nums.begin(), nums.end());
        ll count = 0;

        // for (int i = 0; i < nums.size()-1; i++) {
        //     for (int j = i+1; j < nums.size(); j++) {
        //         int val = nums[i] + nums[j];
        //         if (val >= lower and val <= upper) {
        //             // std::cout << "(" << i << ", " << j << "), ";
        //             count++;
        //         }
        //     }
        // }

        // target = nums[i] + nums[j] -> target - nums[i] = nums[j]
        for (int i = 0; i < nums.size(); i++) {
            int left = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = std::upper_bound(nums.begin() + i + 1, nums.end(), upper-nums[i]) - nums.begin();

            count += right - left;
        }

        return count;
    }
};

int main() {
    std::vector<int> nums {0,1,7,4,4,5};
    std::cout << (new Solution)->countFairPairs(nums, 3, 6);
}
