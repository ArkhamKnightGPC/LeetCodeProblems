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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode();
        ListNode *curr = ret;

        int go_one = 0;
        while(l1 && l2){
            int sum = (l1->val + l2->val + go_one);
            go_one = (sum > 9) ? 1 : 0;
            sum = sum%10;
            curr->val = sum;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 && l2){
                curr->next = new ListNode();
                curr = curr->next;
            }
        }

        while(l1){
            curr->next = new ListNode();
            curr = curr->next;
            int sum = (l1->val + go_one);
            go_one = (sum > 9) ? 1 : 0;
            sum = sum%10;
            curr->val = sum;
            l1 = l1->next;
        }
        while(l2){
            curr->next = new ListNode();
            curr = curr->next;
            int sum = (l2->val + go_one);
            go_one = (sum > 9) ? 1 : 0;
            sum = sum%10;
            curr->val = sum;
            l2 = l2->next;
        }
        if(go_one){
            curr->next = new ListNode();
            curr = curr->next;
            curr->val = 1;
        }
        return ret;
    }
};