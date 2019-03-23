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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* p = head;
        ListNode* pre = dummy_head;
        while(p != NULL){
            if (p->val == val){
                pre->next = p->next;
                p = p->next;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return dummy_head->next;
    }
};