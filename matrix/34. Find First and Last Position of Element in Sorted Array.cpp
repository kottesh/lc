#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = nums.size();
       
        if (n == 1) {
            if (nums[0] == target)
                return std::vector<int> {0, 0};
            return std::vector<int> {-1, -1};
        }

        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r);

            if (nums[mid] == target) {
                if (mid > 0 and mid < n-1)
                    return nums[mid - 1] == target ? std::vector<int> {mid-1, mid} : std::vector<int> {mid, mid+1};
                if (mid == 0)
                    return nums[mid+1] == target ? std::vector<int> {mid, mid + 1} : std::vector<int> {mid, mid};
                else 
                    return nums[mid-1] == target ? std::vector<int> {mid - 1, mid} : std::vector<int> {mid, mid};
            }
            else if (nums[mid] > target) r = mid - 1; 
            else l = mid + 1;
        } 

        return std::vector<int>{-1, -1};
    }
};

int main() {
    std::vector<int> nums {5,7,7,8,8,10};
    std::vector<int> ans = (new Solution())->searchRange(nums, 8);

    for (auto val : ans) std::cout << val << ", ";
}
