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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        while (head != NULL) {
            if (nodes.find(head) != nodes.end()) {
                return head;
            }
            nodes.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;         
        while (fast != NULL && fast->next != NULL) {         
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }            
        
        fast = head;
        while (fast != slow) {            
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;        
    }
};

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
    ListNode *detectCycle(ListNode *head) {        
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }            
        
        fast = head;
        while (fast != slow) {            
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;    
    }
};