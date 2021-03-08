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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* leftPrev = dummy;
        for (int i = 1; i < left; i++) {
            leftPrev = leftPrev->next;            
        }
        ListNode *curr = leftPrev->next, *prev = NULL, *rightNext = NULL, *leftLast = curr;                
        for (int i = left; i <= right; i++) {
            rightNext = curr->next;
            curr->next = prev;            
            prev = curr;
            curr = rightNext;
        }
        leftLast->next = rightNext;
        leftPrev->next = prev;
        head = dummy->next;
        delete dummy;
        return head;        
    }
};