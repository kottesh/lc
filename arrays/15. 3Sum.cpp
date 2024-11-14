#include <bits/stdc++.h>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> store;

        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int x = nums[i];
            int left = i + 1, right = nums.size() - 1; 

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < -x) left++;
                else if (sum > -x) right--;
                else {
                    store.push_back({x, nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return store;
    }
};

int main() {
    std::vector<int> a {-1,0,1,2,-1,-4};
    (new Solution())->threeSum(a);
}


