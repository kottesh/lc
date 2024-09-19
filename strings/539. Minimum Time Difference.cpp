#include <bits/stdc++.h>

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);
        std::vector<int> store;
        for (auto &time : timePoints) {
           int hh = stoi(time.substr(0, 2)) * 60;
           int mm = stoi(time.substr(3, 2));
           store.push_back(hh + mm);
        }

        sort(store.rbegin(), store.rend());
        
        int min_diff = INT_MAX;
        for (int i =0; i < store.size() - 1; i++) {
            min_diff = std::min(min_diff, store[i] - store[i+1]);
        }

        min_diff = std::min(min_diff, 1440 - (store[0] - store[store.size() -  1]));
        return min_diff;
    }
};
