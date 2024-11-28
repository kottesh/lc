#include <bits/stdc++.h>

class Solution {
    std::unordered_map<char, char> s_map;
    std::unordered_map<char, char> t_map;
public:
    bool isIsomorphic(std::string s, std::string t) {
        for (int i = 0; i < s.length(); i++) {
            if (s_map.find(s[i]) == s_map.end())
                s_map[s[i]] = t[i];
            if (t_map.find(t[i]) == t_map.end())
                t_map[t[i]] = s[i];

            if (s_map[s[i]] != t[i] or t_map[t[i]] != s[i])
                return false;
        }

        return true;
    }
};

int main() {
    std::cout << (new Solution())->isIsomorphic("egg", "add"); 
    std::cout << (new Solution())->isIsomorphic("foo", "bar"); 
    std::cout << (new Solution())->isIsomorphic("paper", "title"); 
}


