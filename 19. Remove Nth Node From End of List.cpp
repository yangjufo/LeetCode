class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        
        ListNode* fp, *lp;
        fp = lp = dummy_head;
        
        int count = 0;
        
        while (lp != NULL){
            lp = lp->next;
            
            if (count == n + 1)
                fp = fp->next;            
            else
                count++;            
        }
        
        ListNode* tmp = fp->next;
                
        fp->next = tmp->next;
        
        free(tmp);                
        
        head = dummy_head->next;
        
        return head;
    }
};