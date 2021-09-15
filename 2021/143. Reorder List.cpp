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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *rightHead = NULL, *ahead = slow;                 
        while (ahead != NULL) {
            ListNode* next = ahead->next;
            ahead->next = rightHead;
            rightHead = ahead;
            ahead = next;
        }        
                
        ListNode* leftHead = head;
        while (rightHead->next != NULL) {
            ListNode *leftNext = leftHead->next, *rightNext = rightHead->next;            
            leftHead->next = rightHead;
            rightHead->next = leftNext;
            leftHead = leftNext;
            rightHead = rightNext;            
        }                                        
    }
};

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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode* slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = slow, *right = slow->next;
        slow->next = NULL;
        while (right != NULL) {
            ListNode* next = right->next;
            right->next = prev;
            prev = right;
            right = next;
        }
        ListNode* left = head;
        right = prev;
        while (left != NULL && right != NULL) {
            ListNode* leftNext = left->next, *rightNext = right->next;
            left->next = right;
            right->next = leftNext;
            left = leftNext;
            right = rightNext;
        }        
    }
};