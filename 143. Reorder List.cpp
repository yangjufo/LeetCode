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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *last = head;
        ListNode *mid = head;
        int count = 1;
        while(last->next != NULL){
            count++;
            last = last->next;
        }
        int pos = 0;
        while (pos != count / 2){
            mid = mid->next;
            pos++;
        }
        ListNode* start = head;
        ListNode* pre;
        while(mid->next != NULL){
            last = mid;
            pre = mid;
            last = last->next;
            while(last->next != NULL){
                last = last->next;
                pre = pre->next;
            }
            last->next = start->next;
            start->next = last;
            pre->next = NULL;
            start = start->next->next;
        }
    }
}; 