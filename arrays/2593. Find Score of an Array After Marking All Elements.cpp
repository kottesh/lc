#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    ll findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> h;
        vector<bool> marked(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            h.push({nums[i], i});
        }

        ll score = 0;

        while (!h.empty()) {
            while (marked[h.top().second] and !h.empty()) {
                h.pop();
            }
            if (h.empty()) break;

            const auto& [val, idx] = h.top();

            marked[idx] = 1;
            if (idx - 1 >= 0) {
                marked[idx - 1] = 1;
            }
            if (idx + 1 < nums.size()) {
                marked[idx + 1] = 1;
            }

            score += val;
        }

        return score;
    }
};

int main() {
    vector<int> nums = {10,44,10,8,48,30,17,38,41,27,16,33,45,45,34,30,22,3,42,42};
    cout << (new Solution())->findScore(nums);
}
