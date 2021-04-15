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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyLeft = new ListNode(), *dummyRight = new ListNode();
        ListNode *prevLeft = dummyLeft, *prevRight = dummyRight;
        while (head != NULL) {
            if (head->val < x) {
                prevLeft->next = head;
                prevLeft = head;                
            } else {
                prevRight->next = head;
                prevRight = head;
            }
            head = head->next;
        }
        prevRight->next = NULL;
        prevLeft->next = dummyRight->next;
        head = dummyLeft->next;
        delete dummyLeft, dummyRight;
        return head;
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = new ListNode(), *rightHead = new ListNode();
        ListNode *leftPrev = leftHead, *rightPrev = rightHead;
        while (head != NULL) {
            if (head->val < x) {
                leftPrev->next = head;
                leftPrev = head;
            } else {
                rightPrev->next = head;
                rightPrev = head;
            }            
            head = head->next;
        }
        leftPrev->next = rightHead->next;
        rightPrev->next = NULL;
        head = leftHead->next;
        delete leftHead, rightHead;
        return head;
    }
};