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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) return NULL;
        int size = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < size / 2 - 1; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};