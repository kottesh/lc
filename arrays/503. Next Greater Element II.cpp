#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> nextGreaterElements(const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        std::stack<int> s;

        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[i % n] > nums[s.top()]) {
                res[s.top()] = nums[i % n];
                s.pop();
            } 
            if (i < n)
                s.push(i % n);
        }

        return res;
    }
};

int main() {
    std::vector<int> res = (new Solution())->nextGreaterElements(std::vector<int> {1, 2, 1});
    for (int val : res) std::cout << val ;
}

