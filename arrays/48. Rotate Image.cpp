#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> cp(matrix); 
        for(int i=0; i<matrix.size(); i++) {
            for(int j = 0; j< matrix[i].size(); j++) {
                matrix[i][j] = cp[j][i];
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
