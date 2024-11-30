#include <bits/stdc++.h>

class Solution {
private:
    int findCount(const std::vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int count = 0;
        int l = 0, r = 0, sum = 0;

        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }

        return count;
    }
public:
    int numSubarraysWithSum(const std::vector<int>& nums, int goal) {
        return findCount(nums, goal) - findCount(nums, goal - 1);
    }
};

int main() {
    std::cout << (new Solution())->numSubarraysWithSum(std::vector<int> {0, 0, 0, 0, 0}, 0);
}

