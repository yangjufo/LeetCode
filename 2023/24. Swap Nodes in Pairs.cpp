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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(), *prev = dummy;
        prev->next = head;
        while (head != NULL && head->next != NULL) {
            ListNode* next = head->next->next;
            prev->next = head->next;
            head->next->next = head;
            head->next = NULL;
            prev = head;
            head = next;
        }
        if (head != NULL) {
            prev->next = head;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};