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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL) {            
            int i = 0;
            ListNode* subPrev = NULL, *firstNode = curr;
            for (; i < k && curr != NULL; i++) {
                ListNode* next = curr->next;
                curr->next = subPrev;
                subPrev = curr;                
                curr = next;
            }
            if (i < k) {
                ListNode* tmpPrev = NULL;
                while (subPrev != NULL) {
                    ListNode* next = subPrev->next;
                    subPrev->next = tmpPrev;
                    tmpPrev = subPrev;
                    subPrev = next;
                }
                subPrev = firstNode;
            }
            if (prev == NULL) {
                head = subPrev;
            } else {
                prev->next = subPrev;
            }
            prev = firstNode;                                    
        }              
        return head;
    }
};