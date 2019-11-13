/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        while (head != null) {
            ListNode curr = dummy.next, currPrev = dummy;
            while (true) {
                if (curr == null || curr.val >= head.val) {
                    if (curr != head) {
                        ListNode tmp = head.next;
                        prev.next = tmp;
                        currPrev.next = head;
                        head.next = curr;
                        head = tmp;
                    } else {
                        head = head.next;
                        prev = prev.next;
                    }
                    break;
                } else {
                    currPrev = currPrev.next;
                    curr = curr.next;
                }
            }
        }
        return dummy.next;
    }
}
