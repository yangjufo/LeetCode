/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    private ListNode split(ListNode head, int step) {
        if (head == null)
            return null;
        for (int i = 1; head.next != null && i < step; i++)
            head = head.next;
        ListNode right = head.next;
        head.next = null;
        return right;
    }

    private ListNode merge(ListNode left, ListNode right, ListNode prev) {
        ListNode curr = prev;
        while (left != null && right != null) {
            if (left.val < right.val) {
                curr.next = left;
                left = left.next;
            } else {
                curr.next = right;
                right = right.next;
            }
            curr = curr.next;
        }
        if (left != null)
            curr.next = left;
        else if (right != null)
            curr.next = right;
        while (curr.next != null)
            curr = curr.next;
        return curr;
    }

    public ListNode sortList(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int n = 0;
        while (head != null) {
            head = head.next;
            n++;
        }

        for (int step = 1; step < n; step *= 2) {
            ListNode prev = dummy, curr = dummy.next;
            while (curr != null) {
                ListNode left = curr, right = split(left, step);
                curr = split(right, step);
                prev = merge(left, right, prev);
            }
        }

        return dummy.next;
    }
}
