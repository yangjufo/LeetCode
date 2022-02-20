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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode(), *prev = dummy;
        int curr = 0;
        head = head->next;
        while (head != NULL) {
            if (head->val == 0) {
                ListNode* node = new ListNode(curr);
                prev->next = node;
                prev = node;
                curr = 0;
            } else {
                curr += head->val;
            }
            head = head->next;
        }
        return dummy->next;
    }
};