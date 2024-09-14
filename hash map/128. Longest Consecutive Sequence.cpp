#include <bits/stdc++.h>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); std::cout.tie(nullptr);

        //std::unordered_map<int, int> map;      

        //// push all elements onto the map
        //for (auto val : nums) map[val] = val;

        //int max_len = 0;
        //for (auto num : nums) {
        //    int len = 0;
        //    // find the first element in the sequence
        //    if(map.find(num - 1) == map.end()) {
        //        // calculate the length from init element
        //        while(map.find(num++) != map.end()) len++;
        //        // compare to the prev len and 
        //        // assign maximum one to the max_len
        //        max_len = std::max(max_len, len);
        //    } 
        //}
        //return max_len;
       

       int max_len = 0;

       std::sort(nums.begin(), nums.end());

       int last_element = INT_MIN;
          
       int count = 0;
       for (int i = 0; i < nums.size(); i++) {
           if (nums[i] - 1 == last_element)
               count++; 
           else if (nums[i] == last_element)
               continue;
           else
               count = 1;
           last_element = nums[i];
           max_len = std::max(max_len, count);
       }
       return max_len;
    }
};

int main() {
    std::vector<int> a {100,4,200,1,3,2};
    std::cout << (new Solution())->longestConsecutive(a);
    return 0;
}
