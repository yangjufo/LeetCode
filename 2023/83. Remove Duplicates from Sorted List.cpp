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
        if (head == NULL) return head;
        int curr = head->val;
        ListNode *prev = head, *p = head->next;
        while (p != NULL) {
            ListNode* next = p->next;
            if (p->val != curr) {
                curr = p->val;
                prev->next = p;
                prev = p;
            } else {
                prev->next = NULL;
                delete p;
            }
            p = next;
        }
        return head;
    }
};