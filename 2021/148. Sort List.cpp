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
    ListNode* sortList(ListNode* head) {        
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }        
        
        ListNode* end = slow;
        slow = slow->next;
        end->next = NULL;
        fast = sortList(slow);
        slow = sortList(head);
               
        
        ListNode *dummy = new ListNode(), *prev = dummy;
        
        while (slow != NULL && fast != NULL) {            
            if (slow->val > fast->val) {
                prev->next = fast;                
                fast = fast->next;
            } else {
                prev->next = slow;
                slow = slow->next;
            }
            prev = prev->next;            
        }
        if (slow != NULL) prev->next = slow;
        else prev->next = fast;
        return dummy->next;
    }
};