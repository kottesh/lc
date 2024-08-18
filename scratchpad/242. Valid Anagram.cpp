#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> s_map, t_map;

        for (char c : s) {
            s_map[c]++;
        }

        for (char c : t) {
            t_map[c]++;
        }

        return s_map == t_map;
    }
};

int main() {
    Solution solution;
    std::string s = "anagram";
    std::string t = "nagaram";
    
    if (solution.isAnagram(s, t)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}

