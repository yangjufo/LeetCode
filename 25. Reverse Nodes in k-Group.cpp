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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;                    
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* prev = dummy_head;
        head = prev;
        ListNode* tp;
        int i;
        while(head->next != NULL && head->next->next != NULL){
            head = head->next;
            tp = head->next;
            for(i = 1; i < k && head->next != NULL; i++){                
                head->next = tp->next;
                tp->next = prev->next;
                prev->next = tp;
                tp = head->next;                
            }             
            if (i < k && i != 1){
                ListNode* last = head->next;
                while(prev->next != head){
                    tp = prev->next;
                    prev->next = tp->next;
                    head->next = tp;
                    tp->next = last;
                    last = tp;
                }                
            }
            prev = head;                        
        }
        return dummy_head->next;
    }        
};