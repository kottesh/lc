class Solution {
    void findCombinations(vector<vector<int>>& res, int n, int k, vector<int>& curr, int start = 1) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            findCombinations(res, n, k, curr, start + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;  
        vector<int> curr;

        findCombinations(res, n, k, curr);

        return res;
    }
};
