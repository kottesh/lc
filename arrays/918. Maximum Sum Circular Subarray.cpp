#include <bits/stdc++.h>

// referred neetcode. revisit this problem
class Solution {
public:
    int maxSubarraySumCircular(const std::vector<int>& nums) {
        int max_sum = INT_MIN, min_sum = INT_MAX;
        int curr_max = 0, curr_min = 0;
        
        int sum = 0;
        for (int num : nums) {
            sum += num;

            curr_max = std::max(curr_max + num, num);
            curr_min = std::min(curr_min + num, num);
            
            max_sum = std::max(curr_max, max_sum);
            min_sum = std::min(curr_min, min_sum);
        }
        
        return max_sum > 0 ? std::max(max_sum, sum - min_sum) : max_sum;
    }
};

int main () {
    std::cout << (new Solution())->maxSubarraySumCircular(std::vector<int> {5,-3,5});
}
