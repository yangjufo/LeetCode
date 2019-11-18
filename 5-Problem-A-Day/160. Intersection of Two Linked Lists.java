/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; next = null; } }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pA = headA, pB = headB;
        boolean firstA = true, firstB = true;
        while (pA != pB) {
            if (pA == null) {
                if (firstA) {
                    pA = headB;
                    firstA = false;
                } else
                    return null;
            } else
                pA = pA.next;
            if (pB == null) {
                if (firstB) {
                    pB = headA;
                    firstB = false;
                } else
                    return null;
            } else
                pB = pB.next;
        }
        return pB;
    }
}
