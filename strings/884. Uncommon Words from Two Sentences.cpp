#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
        std::unordered_map<std::string, int> store;
        std::vector<std::string> res;

        std::string buffer;
        std::stringstream ss1(s1), ss2(s2);

        while (getline(ss1, buffer, ' ')) {
            store[buffer]++;
        }
        while (getline(ss2, buffer, ' ')) {
            store[buffer]++;
        }

        //int i = 0;
        //int start = 0;
        //while (i < s1.length()) {
        //    while (s1[i] == ' ' && i < s1.length()) i++;
        //    start = i;
        //    while (i < s1.length() && s1[i] != ' ') i++;
        //    store[s1.substr(start, i - start)]++;
        //}

        //i = 0;
        //start = 0;

        //while (i < s2.length()) {
        //    while (s2[i] == ' ' && i < s2.length()) i++;
        //    start = i;
        //    while (i < s2.length() && s2[i] != ' ') i++;
        //    store[s2.substr(start, i -start)]++;
        //}

        for (auto &item : store) {
            std::cout << item.first << std::endl;
            if (item.second == 1) {
                res.push_back(item.first);
            }
        }

        return res;
    }
};

int main() {
    return 0;
}
