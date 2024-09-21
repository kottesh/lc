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
    std::stack<TreeNode*> stk;
    void interchange(TreeNode* node) {
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    void store_node(TreeNode* root) {
        if (!root) return;

        store_node(root->left);
        store_node(root->right);
        stk.push(root);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        store_node(root);
        while (!stk.empty()) {
            interchange(stk.top());
            stk.pop();
        }

        return root;
    }
};

