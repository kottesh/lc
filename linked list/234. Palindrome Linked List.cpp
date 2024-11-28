/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    std::stack<ListNode *> s;
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        ListNode* hd = head;

        while (hd) {
            s.push(hd);
            hd = hd->next;
        }
        
        while (!s.empty()) {
            if (s.top()->val != head->val) return false;
            head = head->next;
            s.pop();
        }
        return true;
    }
};
