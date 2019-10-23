/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = null;
        ListNode prev = null;
        while (l1 != null || l2 != null) {
            int tmp = carry;
            if (l1 != null) {
                tmp += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                tmp += l2.val;
                l2 = l2.next;
            }
            ListNode curr = new ListNode(tmp % 10);
            if (head == null)
                head = curr;
            else
                prev.next = curr;
            prev = curr;
            carry = tmp / 10;
        }
        if (carry != 0)
            prev.next = new ListNode(carry);
        return head;
    }
}
