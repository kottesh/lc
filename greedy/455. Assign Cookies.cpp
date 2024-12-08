#include <bits/stdc++.h>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::cin.tie(0); std::cout.tie(0);
        std::ios_base::sync_with_stdio(false);

        int i = 0, j = 0;
        int count = 0;

        if (!g.size() or !s.size()) return count;

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        while (i < g.size() and j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
                count++;
            }
            j++;
        }

        return count;
    }
};

