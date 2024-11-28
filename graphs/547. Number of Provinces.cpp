#include <bits/stdc++.h>

class Solution {
private:
    std::queue<int> q;

    void bfs(int init, const std::vector<std::vector<int>> &adj, std::vector<int> &visited) {
        visited[init] = true;
        q.push(init);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (const int &it: adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }
public:
    int findCircleNums(const std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        std::vector<int> visited(n, false);
        std::vector<std::vector<int>> adj(n);

        // convert the adj matrix to adj list.
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, adj, visited);
            }
        }

        return count;
    }
};

int main() {
    std::cout << (new Solution())->findCircleNums(std::vector<std::vector<int>> {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}});
    std::cout << (new Solution())->findCircleNums(std::vector<std::vector<int>> {{1,0,0},{0,1,0},{0,0,1}});
}
