#include <bits/stdc++.h>

class Solution {
public:
    // bruteforce

    // int findMaxK(std::vector<int>& nums) {
    //     int max = -1;

    //     for (int i = 0; i < nums.size(); i++) {
    //         int temp = nums[i];
    //         if (!(nums[i] < 0)) {
    //             for (int j = 0; j < nums.size(); j++) {
    //                 if ( i == j ) continue;
    //                 if (temp == -nums[j] && temp > max) {
    //                     max = temp;
    //                 }
    //             }  
    //         }
    //     }

    //     return max;
    // }

    // somewhat optimized approach

    int findMaxK(std::vector<int>& nums) {
        int max = -1;

        std::unordered_set<int> negs;
        std::sort(nums.begin(), nums.end()); // sort the values, by doing this negative values get 
                                             // populated in the hash set first and on hitting the
                                             // positive values, will search for the counter part in the hash set.
        for (int item : nums) {
            if (item > 0) {
                if (negs.contains(-item) && item > max) max = item; 
            } else {
                negs.insert(item);
            }
        } 

        return max;
    } 
};

int main() {
    std::vector<int> store {-1, 10, 6, 7, -7, 1};
    std::cout << (new Solution())->findMaxK(store);
    return 0;
}
