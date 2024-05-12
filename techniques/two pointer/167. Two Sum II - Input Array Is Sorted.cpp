#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> ans(2);

        int low = 0,
            high = numbers.size() - 1,
            current;

        while(low < high) {
            current = numbers[low] + numbers[high];
            if(current == target) {
                ans = {low+1, high+1};
                break;
            }
            else if(current > target)
                high--;
            else
                low++;
        }
        return ans;
    }
};