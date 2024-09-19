#include <bits/stdc++.h>

class Solution {
public:
    int findTheLongestSubstring(std::string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        std::unordered_map<int, int> store = {{0, -1}};
        std::string vowels = "aeiou";

        int state = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            int idx = vowels.find(s[i]);

            if (idx != std::string::npos) {
                state ^= (1 << idx);
            }

            if (store.find(state ) != store.end()) {
                ans = std::max(ans, i - store[state]);
            } else {
                store[state] = i;
            }
        }

        return ans;
    }
};
