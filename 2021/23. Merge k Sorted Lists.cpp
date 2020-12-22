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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto Compare = [](pair<int, ListNode*>& l, pair<int, ListNode*>& r) { return l.first > r.first; };
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, decltype(Compare)> minHeap(Compare);
        for (ListNode* node : lists) {
            if (node != NULL) {
                minHeap.push({node->val, node});
            }
        }
        
        ListNode* dummy_head, *prev;
        dummy_head = new ListNode(0);
        prev = dummy_head;
        
        while (!minHeap.empty()) {
            auto curr = minHeap.top().second;
            minHeap.pop();
            if (curr->next != NULL) {
                minHeap.push({curr->next->val, curr->next});
            }
            prev->next = curr;
            prev = curr;                        
        }
        
        return dummy_head->next;
    }
};