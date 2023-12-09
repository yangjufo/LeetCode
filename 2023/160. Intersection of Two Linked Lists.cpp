/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;
        while (pA != NULL) {
            lenA++;
            pA = pA->next;
        }
        while (pB != NULL) {
            lenB++;
            pB = pB->next;
        }

        pA = headA, pB = headB;
        while (lenA > lenB) {
            pA = pA->next;
            lenA--;
        }
        while (lenB > lenA) {
            pB = pB->next;
            lenB--;
        }

        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }

        return pA;
    }
};