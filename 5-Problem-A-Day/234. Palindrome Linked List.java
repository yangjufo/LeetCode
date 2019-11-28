/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;
        ListNode firstEnd = endOfFirstHalf(head), secondStart = reverse(firstEnd.next);
        ListNode p1 = head, p2 = secondStart;
        boolean ans = true;
        while (ans && p2 != null) {
            if (p1.val != p2.val)
                ans = false;
            p1 = p1.next;
            p2 = p2.next;
        }
        return ans;
    }

    private ListNode reverse(ListNode head) {
        ListNode prev = null, curr = head;
        while (curr != null) {
            ListNode tmp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    private ListNode endOfFirstHalf(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
