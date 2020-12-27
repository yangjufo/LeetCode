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
        ListNode *head = NULL, *prev = NULL;
        int carry = 0, tmp = 0;
        while (l1 != NULL || l2 != NULL) {
            tmp = carry;
            if (l1 != NULL) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                tmp += l2->val;
                l2 = l2->next;
            }
            carry = tmp / 10;
            ListNode* node = new ListNode(tmp % 10);
            if (head == NULL) {
                head = node;                
            } else {
                prev->next = node;
            }
            prev = node;
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            prev->next = node;            
        }
        return head;
    }
};