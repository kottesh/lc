#include <bits/stdc++.h>

class Solution {
    void countRepeat(
        const std::string &seq,
        const std::string &word,
        int curr,
        int &count
    ) {
        if (curr >= seq.length()) return;

        if (curr + word.length() - 1 < seq.length()  and seq.substr(curr, word.length()) == word) {
            count++;
            countRepeat(seq, word, curr+word.length(), count);
            return;
        }

        countRepeat(seq, word, curr+1, count);
    }
public:
    int maxRepeating(std::string sequence, std::string word) {
        int count = 0;
        countRepeat(sequence, word, 0, count);
        return count;
    }
};

int main() {
    std::cout << (new Solution)->maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba");
}
