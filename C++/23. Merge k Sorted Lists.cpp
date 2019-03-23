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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        if (lists.size() == 2){
            ListNode* head = new ListNode(0);
            ListNode* prev = head;
            while (lists[0] != NULL && lists[1] != NULL){
                if (lists[0]->val < lists[1]->val){
                    prev->next = lists[0];
                    prev = lists[0];
                    lists[0] = lists[0]->next;
                }                    
                else{
                    prev->next = lists[1];
                    prev = lists[1];
                    lists[1] = lists[1]->next;
                }
            }
            if (lists[0] != NULL)                
                prev->next = lists[0];
            else if(lists[1] != NULL)
                prev->next = lists[1];
            return head->next;
        }
        else{
            int mid = lists.size() / 2;
            vector<ListNode*> left_lists, right_lists;
            for(int i = 0; i < mid; i++){                
                left_lists.push_back(lists[i]);                
            }                
            for(int i = mid; i < lists.size(); i++){
                right_lists.push_back(lists[i]);
            }
            vector<ListNode*> tmp_res;
            tmp_res.push_back(mergeKLists(left_lists));
            tmp_res.push_back(mergeKLists(right_lists));
            return mergeKLists(tmp_res);            
        }
    }
};