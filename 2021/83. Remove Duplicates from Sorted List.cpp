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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = head, *curr = head->next;        
        while (curr != NULL) {            
            if (prev->val == curr->val) {
                ListNode* toDelete = curr;
                curr = curr->next;
                delete toDelete;
            } else {
                prev->next = curr;
                prev = curr;   
                curr = curr->next;
            }
        }
        prev->next = NULL;
        return head;
    }
};