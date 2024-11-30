#include <bits/stdc++.h>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            std::unordered_map<char, int> map; 
            for (int j = i; j < s.length(); j++) {
                map[s[j]] = 1;
                if (map['a'] + map['b'] + map['c'] == 3) {
                   count++;
                }
            }
        }

        return count;
    }
};

int main() {
    std::cout << (new Solution())->numberOfSubstrings("abcabc");
}
