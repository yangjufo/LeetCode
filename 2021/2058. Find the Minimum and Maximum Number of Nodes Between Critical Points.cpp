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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res = {INT_MAX, INT_MIN};
        ListNode* prev = head;
        head = head->next;
        int index = 0, prevC = -1, firstC = -1;
        while (head != NULL && head->next != NULL) {
            index++;
            if ((head->val > prev->val && head->val > head->next->val) || (head->val < prev->val && head->val < head->next->val)) {
                if (prevC != -1) {                
                    res[0] = min(res[0], index - prevC);                    
                }
                if (firstC != -1) {
                    res[1] = max(res[0], index - firstC);
                } else {
                    firstC = index;
                }                
                prevC = index;                
            }
            prev = head;
            head = head->next;
        }
        if (res[0] == INT_MAX) {
            return {-1, -1};
        }
        return res;
    }
};