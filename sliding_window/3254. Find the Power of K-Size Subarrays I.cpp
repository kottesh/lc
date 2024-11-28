#include <bits/stdc++.h>

class Solution {
public:
    // bruteforce
    std::vector<int> resultsArray(const std::vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);
        std::vector<int> res(nums.size()-k+1, -1);

        for (int i = 0; i < nums.size() - k + 1; i++) {
            int j;
            for (j = i ; j < i + k; j++) {
                if (j == i) continue;
                if ((nums[j] - nums[j-1]) != 1) break;
            }
            if (j == i + k) res[i] = nums[j-1];
        }      

        return res;
    }
};

int main() {
    std::vector<int> res = (new Solution())->resultsArray(std::vector<int> {3,2,3,2,3,2}, 2);
    for (auto val : res) std::cout << val << " ";
}