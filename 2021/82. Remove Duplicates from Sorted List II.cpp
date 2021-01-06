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
        ListNode* dummy = new ListNode(), *prev = dummy;
        while (head != NULL) {
            bool dup = false;
            while (head->next != NULL && head->val == head->next->val) {
                dup = true;
                head = head->next;
            }                        
            if (!dup) {
                prev->next = head;
                prev = prev->next;                
            }
            head = head->next;
        }
        prev->next = NULL;
        return dummy->next;
    }
};