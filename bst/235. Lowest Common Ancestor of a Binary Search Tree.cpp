/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca;
        int min = std::min(q->val, p->val);
        int max = std::max(p->val, q->val);

        while (root) {
            if (min > root->val)
                root = root->right;
            else if (max < root->val)
                root = root->left;
            else break;
        }
        return root;
    }
};
