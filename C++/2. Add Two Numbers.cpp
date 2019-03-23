class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        ListNode* prep = NULL;
        ListNode* root = NULL;
        int c = 0;
        while(l1 != NULL && l2 != NULL){
            l3 = new ListNode((l1->val + l2->val + c) % 10) ;                
            c = (l1->val + l2->val + c) / 10;  
            if (root == NULL){                
                root = l3;
                prep = root;
            }
            else{                                
                prep->next = l3;                
                prep = l3;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL && l2 != NULL){            
            while (l2 != NULL){                
                l3 = new ListNode((l2->val + c) % 10);
                c = (l2->val + c) / 10;
                prep->next = l3;
                prep = l3;
                l2 = l2->next;
            }
        }
        else if(l1 != NULL && l2 == NULL){
            while (l1 != NULL){                
                l3 = new ListNode((l1->val + c) % 10);
                c = (l1->val + c) / 10;
                prep->next = l3;
                prep = l3;
                l1 = l1->next;
            }
        }
        if (c != 0){
            l3 = new ListNode(c);                
            prep->next = l3;                                
        }
        return root;    
    }
};