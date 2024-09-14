#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); std::cout.tie(nullptr);

        std::vector<int> ans; 

        for (auto query : queries) {
            int res = 0;
            for (int i = query[0]; i <= query[1]; i++) {
                res ^= arr[i]; 
            }
            ans.push_back(res);
        }
        return ans;
    }
};
