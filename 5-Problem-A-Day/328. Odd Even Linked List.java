/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode oddHead = new ListNode(0), evenHead = new ListNode(0);        
        ListNode oddPrev = oddHead, evenPrev = evenHead;
        ListNode curr = head;
        boolean even = false;
        while (curr != null) {
            ListNode tmp = curr.next;
            if (even) {
                evenPrev.next = curr;
                curr.next = null;
                evenPrev = curr;
            }
            else {
                oddPrev.next = curr;
                curr.next = null;
                oddPrev = curr;
            }
            even = !even;
            curr = tmp;
        }
        oddPrev.next = evenHead.next;
        return oddHead.next;
    }
}c
