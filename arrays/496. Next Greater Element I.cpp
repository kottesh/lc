#include <bits/stdc++.h>

class Solution {
    std::unordered_map<int, int> map;
public:
    std::vector<int> nextGreaterElement(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> res(nums1.size(), -1);
        std::stack<int> s;

        for(int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > s.top()) {
                map[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = map[nums1[i]] ? map[nums1[i]] : -1;
        }

        return res;
    }
};

int main() {
    std::vector<int> ans = (new Solution())->nextGreaterElement(std::vector<int> {2, 4}, std::vector<int> {1, 2, 3, 4});

    for (auto val : ans) std::cout << val << " ";
}
