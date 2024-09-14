#include <bits/stdc++.h>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr); std::cin.tie(nullptr);
        std::unordered_map<char, char> store;
        for (char ch : allowed) store[ch] = ch;
        
        int count = words.size();
        for (std::string word : words) {
            for (char ch : word) {
                if (store.find(ch) == store.end()) {
                    --count;
                    break;
                }
            }
        }

        //int count = words.size();
        //for (std::string word : words) {
        //    for (int i = 0; i < word.size(); i++) {
        //        if (allowed.find(word[i]) == string::npos) {
        //            count--;
        //            break;
        //        }
        //    }
        //}

        return count;
    }
};
