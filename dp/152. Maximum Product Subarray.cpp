#include <bits/stdc++.h>
#include <cmath>

class Solution {
public:
    int maxProduct(const std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int res = INT_MIN;
        int _prod = nums[0];

        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            int num = *it;
            _prod *= num;
            if (_prod < 0)
                _prod = 1;
            res = std::max(_prod, res);
        }

        return res;
    }
};

int main() {
    std::cout << (new Solution())->maxProduct(std::vector<int> {-2});
}
