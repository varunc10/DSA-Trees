/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *curr=node->next;
        int temp=curr->val;
        curr->val=node->val;
        node->val=temp;
        node->next=curr->next;
        delete curr;
    }
};