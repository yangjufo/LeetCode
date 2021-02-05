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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        bool isOdd = true;
        ListNode *oddHead = head, *evenHead = head->next;
        ListNode *oddPrev = oddHead, *evenPrev = evenHead;
        head = evenHead->next;
        oddHead->next = NULL, evenHead->next = NULL;
        while (head != NULL) {
            if (isOdd) {
                oddPrev->next = head;
                oddPrev = head;
            } else {
                evenPrev->next = head;
                evenPrev = head;
            }
            head = head->next;
            isOdd = !isOdd;            
        }
        evenPrev->next = NULL;
        oddPrev->next = evenHead;
        return oddHead;
    }
};