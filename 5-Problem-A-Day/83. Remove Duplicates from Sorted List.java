/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return null;
        ListNode ans = head, prev = head;
        int count = 1, curr = head.val;
        head = head.next;
        while (head != null) {
            if (head.val != curr) {
                curr = head.val;
                prev.next = head;
                prev = head;
            }
            head = head.next;
        }
        prev.next = null;
        return ans;
    }
}
