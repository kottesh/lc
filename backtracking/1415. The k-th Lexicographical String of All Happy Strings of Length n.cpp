#include <bits/stdc++.h>

using namespace std;

class Solution {
    void gen_strings(
        string curr,
        const char last,
        vector<string> &store,
        const int &n,
        const int &k
    )  {
        if (store.size() == k) {
            return;
        }
        if (curr.size() == n) {
            store.push_back(curr);
            return;
        }
        
        static char chars[3] = {'a', 'b', 'c'};
        for (const auto &ch : chars) {
            if (ch != last) {
                curr.push_back(ch);
                gen_strings(curr, ch, store, n, k);
                curr.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> store;    
        this->gen_strings("", '\0', store, n, k);
    
        if (k <= store.size()) {
            return store[k - 1];
        } else {
            return "";
        }
    }
};

int main() {
    Solution run = Solution();
    cout << run.getHappyString(3, 9);
}
