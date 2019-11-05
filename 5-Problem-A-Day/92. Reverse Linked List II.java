/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode curr = dummy;
        int count = 0;
        ListNode prev = null, follow = null, before = null, last = null;
        while (curr != null) {
            if (count >= m && count <= n) {
                ListNode tmp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = tmp;
            } else {
                if (count == m - 1) {
                    before = curr;
                    last = curr.next;
                } else if (count == n + 1)
                    follow = curr;
                curr = curr.next;
            }
            count += 1;
        }
        before.next = prev;
        last.next = follow;
        return dummy.next;
    }
}
