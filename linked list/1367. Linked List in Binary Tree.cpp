class Solution {
private:
    bool findMatch(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root || root->val != head->val) return false;

        return (findMatch(head->next, root->left) ||
                findMatch(head->next, root->right));
    } 
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        if (!findMatch(head, root))
            return (isSubPath(head, root->left) || 
                    isSubPath(head, root->right));

        return true;
    }
};

