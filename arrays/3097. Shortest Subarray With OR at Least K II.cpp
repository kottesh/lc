#include <bits/stdc++.h>
#include <vector>

class Solution {
public:
    int minimumSubarrayLength(const std::vector<int>& nums, int k) {
        int start = 0, mn = INT_MAX, val = 0;

        for (int end = 0; end < nums.size(); end++) {
            val |= nums[end];

            while (val >= k && start <= end) {
                std::cout << "MIN: " <<  mn << std::endl;
                mn = std::min(mn, end - start + 1);
                if (nums[start] == 1) {
                    start++;
                    continue;
                }
                val ^= nums[start];
                start++;
            }
        }

        return mn == INT_MAX ? - 1 : mn;
    }
};


int main () {
    std::cout << (new Solution())->minimumSubarrayLength(std::vector<int> {1, 2, 3}, 2) << "\n";
    std::cout << (new Solution())->minimumSubarrayLength(std::vector<int> {1, 2}, 0) << "\n";
    std::cout << (new Solution())->minimumSubarrayLength(std::vector<int> {1, 2, 32, 21}, 55) << "\n";
    std::cout << (new Solution())->minimumSubarrayLength(std::vector<int> {2, 32, 27, 1}, 59) << "\n";
    return 0;
}
