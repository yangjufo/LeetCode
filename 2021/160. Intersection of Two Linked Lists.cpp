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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        while (nodeA != NULL) {
            ListNode *nodeB = headB;
            while (nodeB != NULL && nodeB != nodeA) {
                nodeB = nodeB->next;
            }
            if (nodeB != NULL) {
                return nodeB;
            }
            nodeA = nodeA->next;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> setA;
        while (headA != NULL) {
            setA.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL && setA.find(headB) == setA.end()) {
            headB = headB->next;
        }
        return headB;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;
        while (pA != NULL) {
            lenA++;
            pA = pA->next;
        }
        while (pB != NULL) {
            lenB++;
            pB = pB->next;            
        }
        
        pA = headA, pB = headB;
        while (lenA > lenB) {
            pA = pA->next;
            lenA--;
        }
        while (lenB > lenA) {
            pB = pB->next;
            lenB--;
        }
        
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        
        return pA;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = (pA == NULL) ? headB : pA->next;
            pB = (pB == NULL) ? headA : pB->next;
        }
        return pA;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;
        while (pA != NULL) {
            lenA++;
            pA = pA->next;
        }
        while (pB != NULL) {
            lenB++;
            pB = pB->next;
        }
        if (lenA < lenB) {
            pA = headB;
            pB = headA;
        } else {
            pA = headA;
            pB = headB;
        }
        for (int i = 0; i < abs(lenA - lenB); i++) {
            pA = pA->next;
        }
        while (pA != NULL && pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};