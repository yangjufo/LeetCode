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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rearHead = reverseList(slow->next);
        slow->next = NULL;
        ListNode* newHead = head;
        while (head != NULL && rearHead != NULL) {
            ListNode* headNext = head->next, *rearHeadNext = rearHead->next;
            head->next = rearHead;
            rearHead->next= headNext;
            head = headNext;
            rearHead = rearHeadNext;
        }
    }
};