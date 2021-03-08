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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        while (head != NULL) {
            ListNode *curr = dummy->next, *prev = dummy;
            while (curr != NULL && head->val > curr->val) {
                prev = curr;
                curr = curr->next;                
            }
            prev->next = head;
            head = head->next;
            prev->next->next = curr;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};