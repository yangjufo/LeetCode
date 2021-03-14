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
    ListNode* swapNodes(ListNode* head, int k) {               
        ListNode* left = head, *right = head;
        ListNode* root = head;
        for (int i = 1; i < k; i++) {
            left = left->next;
            head = head->next;
        }
        
        while (head->next != NULL) {
            right = right->next;
            head = head->next;
        }
        
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
        return root;
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left = head;
        for (int i = 1; i < k; i++) {
            left = left->next;
        }
        ListNode *right = head, *fast = left->next;        
        while (fast != NULL) {
            right = right->next;
            fast = fast->next;
        }
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
        return head;
    }
};