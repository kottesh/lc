#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode Node;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<vector<int>> res; 
        if(!root) return res;

        std::queue<Node *> q;
        q.push(root);

        while(!q.empty()) {
            std::vector<int> cur_level;
            int q_size = q.size(); // using q_size 'cause if directly the func is used. the value of the q.size() will vary..... 
            for(int i=0; i < q_size; i++) {
                Node *current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                cur_level.push_back(current->val);
            }
            res.insert(res.begin(), cur_level);
        }

        return res;
    }
};
