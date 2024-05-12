#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//preorder type of traversal
void dfs(TreeNode *root, std::vector<int> &vec) {
    if(root == nullptr) {return;}

    if(root->left == nullptr && root->right == nullptr) {
        vec.push_back(root->val);
    }

    dfs(root->left, vec);
    dfs(root->right, vec);
}
  
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vec1, vec2;

        dfs(root1, vec1);
        dfs(root2, vec2);

        if(vec1.size() == vec2.size()) {
            for(int i=0; i<vec1.size(); i++) {
                if(vec1[i] != vec2[i]) {return false;}
            }
            return true;
        }
        return false;
    }
};