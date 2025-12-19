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
    void swapPairs_augmented(ListNode* cur, ListNode* prev, bool swap) {
        if(!cur)return;
        if(cur && swap){
            int tmp = cur->val;
            cur->val = prev->val;
            prev->val = tmp;
        }
        swapPairs_augmented(cur->next, cur, !swap);
    }
    ListNode* swapPairs(ListNode* head) {
        swapPairs_augmented(head, nullptr, false);
        return head;
    }
};