/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return null;
        ListNode last = head;
        int size = 1;
        while (last.next != null) {
            size += 1;
            last = last.next;
        }
        k %= size;
        ListNode curr = head;
        int count = 1;
        while (curr != null && curr.next != null && count < size - k) {
            curr = curr.next;
            count += 1;
        }
        last.next = head;
        head = curr.next;
        curr.next = null;
        return head;
    }
}
