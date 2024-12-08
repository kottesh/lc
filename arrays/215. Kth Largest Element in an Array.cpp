#include <bits/stdc++.h>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        for (const int num : nums) {
            min_heap.push(num);
            if (min_heap.size() > k) 
                min_heap.pop();
        } 

        return min_heap.top();
    }
};

int main() {
    std::vector<int> nums {3,2,3,1,2,4,5,5,6};
    std::cout << (new Solution())->findKthLargest(nums, 4);
}
