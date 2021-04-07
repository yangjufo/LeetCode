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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(), *prev = dummy;
        dummy->next = head;
        while (head != NULL) {            
            ListNode *next = head->next;
            if (head->val == val) {
                delete head;                
            } else {
                prev->next = head;
                prev = head;                
            }
            head = next;            
        }
        prev->next = NULL;
        head = dummy->next;
        delete dummy;
        return head;
    }
};