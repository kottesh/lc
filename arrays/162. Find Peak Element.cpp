#include <bits/stdc++.h>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int pos;
        for (auto itr = nums.begin(); itr != nums.end(); itr++) {
            if (itr == nums.begin()) {
                if (*itr > *(itr+1)) pos = (std::distance(nums.begin(), itr));
            } else if (itr == nums.end()-1) {
                if (*itr > *(itr-1)) pos = (std::distance(nums.begin(), itr));
            } else if (*itr > *(itr+1) && *itr > *(itr-1)) {
                pos = (std::distance(nums.begin(), itr));
            }
        }

        return pos;
    }
};

int main() {
    std::vector nums {1};

    Solution sol;
    std::cout << sol.findPeakElement(nums);
    return 1;
}