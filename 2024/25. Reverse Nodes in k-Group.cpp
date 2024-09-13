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
    void reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *start = head, *node = head, *dummy = new ListNode(), *prev = dummy;
        while (node != NULL) {
            count += 1;
            ListNode* next = node->next;
            if (count % k == 0) {
                node->next = NULL;
                reverse(start);
                prev->next = node;
                start->next = next;
                prev = start;
                start = next;
            }
            node = next;
        }
        return dummy->next;
    }
};