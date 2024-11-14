#include <algorithm>
#include <bits/stdc++.h>

// class Solution {
// public:
//     std::vector<int> maximumBeauty(
//         std::vector<std::vector<int>>& items,
//         std::vector<int>& queries
//     ) {
//         std::vector<int> ans(queries.size(), 0);
//         std::map<int, int> map;

//         for (auto &item : items)
//                 map[item[0]] = std::max(map[item[0]], item[1]);

//         int maxBeatuy = 0;
//         for (auto& [price, beauty] : map) {
//             maxBeatuy = std::max(beauty, maxBeatuy);
//             beauty = maxBeatuy;
//         }

//         for (int i = 0; i < queries.size(); i++) {
//             auto it = map.lower_bound(queries[i]);
//             if (it == map.end()) {
//                 ans[i] = (map.rbegin())->second;
//             } else {
//                 if (it->first == queries[i])
//                     ans[i] = it->second;
//                 else {
//                     if (it == map.begin()) {
//                         ans[i] = 0;
//                     } else {
//                        it--;
//                        ans[i] = it->second;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    std::vector<int> maximumBeauty(
        std::vector<std::vector<int>>& items,
        std::vector<int>& queries
    ) {
        std::vector<int> ans(queries.size());

        std::sort(items.begin(), items.end());

        int max_beauty = 0;
        for (auto &item : items) {
            max_beauty = std::max(item[1], max_beauty);
            item[1] = max_beauty;
        }

        for (int i = 0; i < queries.size(); i++) {
            auto it = std::lower_bound(items.begin(), items.end(), std::vector<int> {queries[i], 0},
                [] (const std::vector<int> &a, const std::vector<int> &b){
                    return a[0] >= b[0];
                }
            );

            if (it == items.end()) {
                ans[i] = 0;
            } else {
                if ((*it)[0] == queries[i]) ans[i] = (*it)[1];
                else {
                    --it;
                    if (it == items.begin()) {
                        ans[i] = items.begin()[1];
                        continue;
                    }

                    ans[i] = (*it)[1];
                }
            }
        }

        return ans;
    }
};
