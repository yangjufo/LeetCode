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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(), *prev = dummy;
        while (list1 != NULL || list2 != NULL) {
            if (list2 == NULL || (list1 != NULL && list1->val < list2->val)) {
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                prev = list2;
                list2 = list2->next;
            }
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};