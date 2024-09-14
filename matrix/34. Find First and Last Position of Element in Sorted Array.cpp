#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r);

            if (nums[mid] == target) {
                if (nums.size() != 1)
                    return nums[mid - 1] == target ? std::vector<int> {mid-1, mid} : std::vector<int>{mid, mid + 1};
                else
                    return std::vector<int> {0, 0};
            }
            else if (nums[mid] > target) r = mid - 1; 
            else l = mid + 1;
        } 

        return std::vector<int>{-1, -1};
    }
};
