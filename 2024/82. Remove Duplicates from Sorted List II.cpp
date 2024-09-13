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
        ListNode* dummy = new ListNode(101), *prev = dummy;
        while (head != NULL) {
            ListNode* curr = head;
            int val = head->val, count = 0;
            while (head != NULL && head->val == val) {
                count += 1;
                head = head->next;
            }
            if (count == 1) {
                prev->next = curr;
                prev = curr;
                prev->next = NULL;
            }
        }
        return dummy->next;
    }
};