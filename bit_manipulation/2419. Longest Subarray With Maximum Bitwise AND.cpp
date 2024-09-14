#include <bits/stdc++.h>

class Solution {
public:
    int longestSubarray(const std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); std::cout.tie(nullptr);
        int max_e = *std::max_element(nums.begin(), nums.end());
        
        int m_count = INT_MIN; //max_count;
        //for (int i = 0; i < nums.size(); i++) {
        //    int count = 0;
        //    if (nums[i] == max_e) {
        //        while (nums[i] == max_e) {
        //            i++;
        //            count++;
        //            if (i == nums.size()) break;
        //        }
        //    }
        //    m_count = std::max(m_count, count);
        //}
        
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_e) {
                count++;
            } else {
                count = 0;
            }
            m_count = std::max(count, m_count);
        }
        return m_count;
    }
};

int main() {
    std::cout << (new Solution())->longestSubarray(std::vector<int> {1, 2, 3, 4}); 
    return 0;
}
