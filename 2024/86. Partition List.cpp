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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(), *right = new ListNode();
        ListNode* prevLeft = left, *prevRight = right;
        while (head != NULL) {
            ListNode* next = head->next;
            if (head->val < x) {
                prevLeft->next = head;
                prevLeft = head;
            } else {
                prevRight->next = head;
                prevRight = head;
            }
            head->next = NULL;
            head = next;
        }
        prevLeft->next = right->next;
        return left->next;
    }
};