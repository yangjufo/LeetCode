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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;        
        ListNode* p = head->next;
        while(p != NULL){
            head->next = p->next;
            p->next = dummy_head->next;
            dummy_head->next = p;
            p = head->next;
        }
        return dummy_head->next;
    }
};
