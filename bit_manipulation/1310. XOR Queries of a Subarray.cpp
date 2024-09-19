#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); std::cout.tie(nullptr);

        std::vector<int> ans; 

        //for (auto query : queries) {
        //    int res = 0;
        //    for (int i = query[0]; i <= query[1]; i++) {
        //        res ^= arr[i]; 
        //    }
        //    ans.push_back(res);
        //}
       
        std::vector<int> prefix(arr.size()+1); // prefix array
        
        prefix[0] = 0;
        for (int i = 1; i < prefix.size(); i++)
            prefix[i] = prefix[i-1] ^ arr[i-1];

        for (auto query : queries) 
            ans.push_back(prefix[query[1]+1] ^ prefix[query[0]]);

        return ans;
    }
};

