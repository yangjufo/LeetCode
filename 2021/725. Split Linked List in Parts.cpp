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
        int size = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        
        vector<ListNode*> res;        
        int count = 0, extra = size - (size / k * k);
        curr = head;        
        while (curr != NULL) {
            ListNode* next = curr->next;
            count++;
            if ((count == size / k && extra <= 0) || (count == size / k + 1 && extra > 0)) {
                res.push_back(head);
                curr->next = NULL;
                head = next;
                count = 0;
                extra--;
            }
            curr = next;
        }
        for (int i = res.size(); i < k; i++) {
            res.push_back(NULL);
        }
        return res;
    }
};