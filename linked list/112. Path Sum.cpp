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

class Solution {
private:
    bool doesExist(TreeNode* root, int targetSum, int currSum) {
        if (!root) return false; 

        if (!root->left && !root->right && root->val + currSum == targetSum)
            return true;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return  
    }
};
