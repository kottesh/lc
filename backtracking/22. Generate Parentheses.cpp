#include <bits/stdc++.h>

using namespace std;

class Solution {
    void generate(vector<string>& res, int n, int count_o = 0, int count_c = 0, string curr = "") {
        if (count_o == count_c and curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        } 

        if (count_o < n)
            generate(res, n, count_o + 1, count_c, curr + "(");
        if (count_c < count_o)
            generate(res, n, count_o, count_c + 1, curr + ")");
    }
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> res;

        generate(res, n);
        
        return res;
    }
};

int main() {
    vector<string> res = (new Solution())->generateParenthesis(2);

    for (auto& item : res)
        cout << item << "\n";
}

