#include <bits/stdc++.h>

class Solution {
    std::priority_queue<std::pair<int, int>> pqueue; // holds int -> score, int -> index in the original vec 
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        for (int i = 0; i < score.size(); i++) {
            pqueue.push(std::make_pair(score[i], i));
        }

        std::vector<std::string> ranks(score.size());
        for (int i = 0; !pqueue.empty(); i++) {
            auto current = pqueue.top();
            pqueue.pop();
            if (i == 0) {
                ranks[current.second] = "Gold Medal";
            } else if (i == 1) {
                ranks[current.second] = "Silver Medal";
            } else if (i == 2) {
                ranks[current.second] = "Bronze Medal";
            } else {
                ranks[current.second] = std::to_string(i+1);
            }
        }

        return ranks;
    }
};
