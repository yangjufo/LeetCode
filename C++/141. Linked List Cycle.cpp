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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* p = head->next;
        while (p != NULL){
            if (head == head->next)
                return true;
            head->next = p->next;
            p->next = dummy_head->next;
            dummy_head->next = p;
            p = head->next;
        }
        return false;
    }
};
