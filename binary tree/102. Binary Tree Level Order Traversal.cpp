#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::queue<TreeNode *> q;
        std::vector<std::vector<int>> res;

        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            std::vector<int> temp;
            for (int i = 0; i < count; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
