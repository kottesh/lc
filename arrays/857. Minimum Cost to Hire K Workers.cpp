#include <bits/stdc++.h>

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int N = wage.size();
        double min_cost = std::numeric_limits<double>::max();

        // workers ratio less than the leader ratio won't be able to form paid group
        std::vector<std::pair<double, int>> worker_ratio(N);
        for (int idx = 0; idx < N; idx++) {
            worker_ratio[idx] = std::make_pair((double)wage[idx]/quality[idx], quality[idx]);
        }
        std::sort(worker_ratio.begin(), worker_ratio.end());

        for (int leader = k-1; leader < N; leader++) {
            double leader_ratio = worker_ratio[leader].first;
            std::vector<double> accepted_offers;

            for (int worker = 0; worker < leader+1; worker++) {
                double offer = worker_ratio[worker].second * leader_ratio;
                accepted_offers.push_back(offer);
            }

            // to find the sum of K smallest element. I will use the max Heap method here. 
            std::priority_queue<double, std::vector<double>> max_heap;
            double sum_heap = 0;

            for (int idx = 0; idx < k; idx++) {
                max_heap.push(accepted_offers[idx]);
                sum_heap += accepted_offers[idx];
            }

            for (int idx = k; idx < accepted_offers.size(); idx++) {
                if (!max_heap.empty() && max_heap.top() > accepted_offers[idx]) {
                    sum_heap -= max_heap.top();
                    max_heap.pop();
                    max_heap.push(accepted_offers[idx]);
                    sum_heap += accepted_offers[idx];
                } 
            }

            double cost = sum_heap;
            min_cost = std::min(cost, min_cost);
        }
        return min_cost;
    }
};
