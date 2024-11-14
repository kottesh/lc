#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>

// memo
class Solution {
    std::unordered_map<int, int> memo;
private:
    int robbing(const std::vector<int> &houses, int start) {
        if (start >= houses.size()) return 0;

        if (memo.find(start) != memo.end()) return memo[start];
        memo[start] = std::max(houses[start] + robbing(houses, start+2), robbing(houses, start+1));
        return memo[start];
    }
public:
    int rob(const std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);

        memo.clear();
        return robbing(nums, 0);
    }
};

// tabulation
// class Solution {
//     public:
//     int rob(const std::vector<int>& nums) {
//         if (nums.size() == 0) return 0;
//         else if (nums.size() == 1) return nums[0];

//         int house1 = nums[0];
//         int house2 = std::max(nums[1], house1);

//         for (int i = 2; i < nums.size(); i++) {
//             int temp = std::max(nums[i]+house1, house2);
//             house1 = house2;
//             house2 = temp;
//         }

//         return house2;
//     }
// };

int main() {
    std::cout <<  (new Solution())->rob(std::vector<int> {5, 3, 10, 10, 15, 7, 20});
}
