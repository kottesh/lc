#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    std::vector<int> result;
public:
    void inorder(TreeNode *root) {
        if(root != nullptr) {
            inorder(root->left);
            result.push_back(root->val);
            inorder(root->right);
        }
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
};