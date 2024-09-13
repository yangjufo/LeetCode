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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode *prev = NULL, *tailPrev = NULL, *tail = head;
        int index = 1;
        while (tail != NULL) {
            if (index < left) {
                prev = tail;
            }
            tailPrev = tail;
            tail = tail->next;
            if (index >= right) {
                break;
            }
            index += 1;
        }
        tailPrev->next = NULL;
        ListNode* middleTail = prev == NULL ? head : prev->next;
        ListNode* middle = reverse(middleTail);
        if (prev != NULL) {
            prev->next = middle;
        } else {
            head = middle;
        }
        middleTail->next = tail;
        return head;
    }
};