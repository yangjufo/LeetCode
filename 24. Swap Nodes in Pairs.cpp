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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* left, *right, *prev, *dummy_head;
        dummy_head = new ListNode(0);
        prev = dummy_head;
        prev->next = head;
        left = dummy_head;        
        while(left->next != NULL && left->next->next != NULL){
            left = left->next;
            right = left->next;
            left->next = right->next;
            right->next = left;
            prev->next = right;
            prev = left;                        
        }        
        return dummy_head->next;        
    }
};