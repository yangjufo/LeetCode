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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        ListNode* oldTail = head;
        int n = 1;
        for (; oldTail->next != NULL; n++) {
            oldTail = oldTail->next;
        }
        oldTail->next = head;

        ListNode* newTail = head;
        for (int i = 0; i < n - k % n - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        newTail->next = NULL;
        return newHead;

    }
};