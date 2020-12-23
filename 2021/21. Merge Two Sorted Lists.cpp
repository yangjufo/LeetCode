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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        
        ListNode *head = NULL, *prev = NULL; 
        while (l1 != NULL || l2 != NULL) {
            ListNode* curr = NULL;
            if (l1 == NULL || (l2 != NULL && l2->val < l1->val)) {                
                curr = l2;
                l2 = l2->next;            
            } else {
                curr = l1;
                l1 = l1->next;
            }            
            if (head == NULL) {
                head = curr;
                prev = curr;
            } else {
                prev->next = curr;
                prev = prev->next;
            }
        }
        return head;
    }
};