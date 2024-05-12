#include <iostream>


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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0, carry=0;
        ListNode *res = nullptr, *temp;
        while(l1 !=nullptr || l2 != nullptr || carry) {
            add = 0;
            l1 != nullptr?add += l1->val: add += 0;
            l2 != nullptr?add += l2->val: add += 0;

            add += carry;
            carry = add / 10;
            if (carry > 0) {
                add = add % 10;
            }

            if(res == nullptr) {
                res = new ListNode(add);
                temp = res;
            } else {
                temp->next = new ListNode(add);
                temp = temp->next;
            }


            l1 != nullptr?l1 = l1->next: l1 = nullptr; 
            l2 != nullptr?l2 = l2->next: l2 = nullptr; 
        }
        return res;
    }
};




int main() {
    ListNode *l1 = nullptr, *l2 = nullptr, *tmp1, *tmp2;
    
    for(int i=1; i<=3; i++) {
        if(l1 == nullptr) {
            l1 = new ListNode(i); 
            l2= new ListNode(i+1); 
            tmp1 = l1;
            tmp2 = l2;
        }
        else {
            tmp1->next = new ListNode(i); 
            tmp2->next = new ListNode(i+1); 
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }

    /*std::cout<<"l1\n";
    while(l1 != nullptr) {
        std::cout<<l1->val<<", ";
        l1 = l1->next;
    }
    std::cout<<"\nl2\n";
    while(l2 != nullptr) {
        std::cout<<l2->val<<", ";
        l2 = l2->next;
    }*/

    Solution sol;
    ListNode *l3 = sol.addTwoNumbers(l1, l2);

    if(l3 == nullptr) {
        std::cout<<"it is null"<<std::endl;
    } else {
        std::cout<<"its not null"<<std::endl;
    }

    while(l3 != nullptr) {
        std::cout<<l3->val<<", ";
        l3 = l3->next;
    }
    return 0;
}