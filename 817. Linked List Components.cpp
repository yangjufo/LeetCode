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
    int numComponents(ListNode* head, vector<int>& G) {
        if (G.empty())
            return 0;
        int count = 0;
        ListNode* start = head;
        while(head != NULL){
            if(find(G.begin(), G.end(), head->val) == G.end()){
                if (start != head)
                    count++;                
                start = head->next;
            }            
            else if(head->next == NULL){
                 count++;                
            }
            head = head->next;            
        }
        return count;
    }
};