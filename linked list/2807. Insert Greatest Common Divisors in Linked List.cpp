#include <bits/stdc++.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode* Node;

class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;

        Node curr = head;
        Node nxt = curr->next;

        while (true) {
            int a, b;
            Node new_n = curr->val > nxt->val ? 
                            new ListNode(gcd(curr->val, nxt->val)) :
                            new ListNode(gcd(nxt->val, curr->val));
            new_n->next = curr->next;
            curr->next = new_n;
            curr = nxt;
            if (!nxt->next) break;
            nxt = nxt->next;
        }

        return head;
    }
};

int main() {

    return 0;
}