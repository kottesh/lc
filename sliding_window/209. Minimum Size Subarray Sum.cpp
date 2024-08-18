#include <bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int window_sum = 0,
            window_length = INT_MAX,
            window_start = 0;

        for (int window_end = 0 ; window_end < nums.size(); window_end++) {
            window_sum += nums[window_end];

            while (window_sum >= target) {
                window_length = std::min(window_length, window_end - window_start + 1);
                window_sum -= nums[window_start];
                window_start++;
            }
        }

        if (window_length == INT_MAX) return 0;

        return window_length;
    }
};