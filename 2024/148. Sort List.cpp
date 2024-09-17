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
    ListNode* sortList(ListNode* head) {
        int total = 0;
        ListNode* node = head;
        while (node != NULL) {
            total += 1;
            node = node->next;
        }
        return sort(head, total);
    }

    ListNode* sort(ListNode* head, int total) {
        if (total <= 1 || head == NULL) {
            return head;
        }
        ListNode* rightHead = head, *prev = NULL;
        int index = 0;
        for (; index < total / 2 && rightHead != NULL; index++) {
            prev = rightHead;
            rightHead = rightHead->next;
        }
        prev->next = NULL;
        ListNode* left = sort(head, index);
        ListNode* right = sort(rightHead, total - index);
        ListNode* dummy = new ListNode();
        prev = dummy;
        while (left != NULL || right != NULL) {
            if (left == NULL || (right != NULL && left->val > right->val)) {
                prev->next = right;
                prev = right;
                right = right->next;
            } else {
                prev->next = left;
                prev = left;
                left = left->next;
            }
        }
        return dummy->next;
    }
};