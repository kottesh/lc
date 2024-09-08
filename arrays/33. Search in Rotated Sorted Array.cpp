#include <bits/stdc++.h>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[l]) { // left sorted portion
                if (nums[mid] < target || nums[l] > target) l = mid + 1;
                else r = mid - 1; 
            } else { // right sorted portion
                if (nums[mid] > target || nums[r] < target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    std::cout << (new Solution())->search(std::vector<int>{4,5,6,7,0,1,2}, 0);
}
