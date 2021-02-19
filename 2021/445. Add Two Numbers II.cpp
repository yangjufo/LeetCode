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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        ListNode* dummy = new ListNode(), *prev = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            prev->next = node;
            prev = node;
        }    
        ListNode *head = dummy->next;
        delete dummy;
        return reverse(head);
    }
    
    ListNode* reverse(ListNode* l) {
        ListNode* prev = NULL;
        while (l != NULL) {
            ListNode* tmp = l->next;
            l->next = prev;
            prev = l;
            l = tmp;
        }
        return prev;
    }
};