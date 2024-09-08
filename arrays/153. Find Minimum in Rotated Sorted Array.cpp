#include <bits/stdc++.h>

class Solution {
public:
    int findMin(const std::vector<int>& nums) {
        int min_val = INT_MAX;
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            if (nums[low] < nums[high]) 
                return std::min(nums[low], min_val);

            int mid = (low + high) / 2;

            min_val = std::min(min_val, nums[mid]);

            if (nums[mid] >= nums[low]) low = mid + 1;
            else high = mid - 1;
        }
        return min_val;
    }
};

int main() {
    std::cout << (new Solution())->findMin(std::vector<int>{3,4,5,1,2});
}
