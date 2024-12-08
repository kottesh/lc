#include <bits/stdc++.h>

struct Compare {
    bool operator()(std::pair<int, int> &a, std::pair<int, int> &b) const {
        return a.first < b.first;
    }
};

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> store;

        for (const int & num : nums) {
            store[num]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> max_heap;

        for (auto& [num, freq] : store) {
            max_heap.push(std::make_pair(freq, num));
        }

        std::vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(max_heap.top().second); 
            max_heap.pop();
        }

        return res;
    }
};

int main() {
    std::vector<int> nums = {1,1,1,2,2,3};
    std::vector<int> res = (new Solution())->topKFrequent(nums, 2);

    for (auto num : res) std::cout << num << " ";
}
