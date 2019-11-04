/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return null;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        int count = 1;
        while (head.next != null) {
            if (head.val != head.next.val) {
                if (count == 1) {
                    prev.next = head;
                    prev = head;
                }
                count = 1;
            } else
                count += 1;
            head = head.next;
        }
        if (count == 1) {
            prev.next = head;
            prev = head;
        }
        prev.next = null;
        return dummy.next;
    }
}
