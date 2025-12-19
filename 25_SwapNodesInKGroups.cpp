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
    void reverseKGroup_augmented(ListNode* cur, vector<ListNode*> nodes, vector<int> vals, int k){
        if(!cur)return;
        nodes.push_back(cur);
        vals.push_back(cur->val);
        if((int)nodes.size() == k){//time to swap
            reverse(vals.begin(), vals.end());
            for(int i=0; i<k; i++){
                ListNode* node = nodes[i];
                int val = vals[i];
                node->val = val;
            }
            nodes.clear();
            vals.clear();
        }
        reverseKGroup_augmented(cur->next, nodes, vals, k);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        reverseKGroup_augmented(head, vector<ListNode*>(), vector<int>(), k);
        return head;
    }
};