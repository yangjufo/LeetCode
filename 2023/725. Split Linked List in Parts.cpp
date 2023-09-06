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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p = head;
        int size = 0;
        while (p != nullptr) {
            size++;
            p = p->next;
        }
        vector<ListNode*> ret;
        int part = size / k, extra = size - (k * part);
        int index = 0;
        while (head != nullptr) {
            int target = part;
            ListNode* curr = head;
            if (ret.size() < extra) {
                target++;
            }
            while (target > 1) {
                curr = curr->next;
                target--;
            }
            ret.push_back(head);
            head = curr->next;
            curr->next = NULL;
        }
        while (ret.size() < k) {
            ret.push_back(NULL);
        }
        return ret;
    }
};