#include <bits/stdc++.h>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> memo;

    void decode(const std::string &str, int &count, int curr) {
        if (curr == str.length()) {
            count++;
            memo[curr] = count;
            return;
        }

        if (str[curr] == '0') return;

        if (memo.find(curr) != memo.end()) {
            count += memo[curr];
            return;
        }

        int org_count = count; // caching the org_count here as the count will get increased and we
                               // keep on using the total_count in the memo value if not cached. inorder to use the
                               // count value of the curr state, we are caching here and later we would take
                               // the difference the org_count and count.

        if (str[curr] - '0'>= 1 and str[curr] - '0' <= 9) {
            decode(str, count, curr+1);
        }
        if (curr + 1 < str.length()) {
            int two_digit = (str[curr] - '0') * 10 + (str[curr+1] - '0');
            if (two_digit <= 26 && two_digit >= 10) {
                decode(str, count, curr+2);
            }
        }

        memo[curr] = count - org_count;
    }
public:
    int numDecodings(const std::string &s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);
        if (s[0] == '0') return 0;

        int count = 0;
        memo.clear();
        decode(s, count, 0);
        return count;
    }
};

int main() {
    std::cout << (new Solution())->numDecodings("1111111111111111111111111111111111");
}
