/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {        
        ListNode ans = new ListNode();
        ListNode head = ans;
        int cnt = 0;
        while (l1 != null || l2 != null) {
            int tmp = cnt;
            if (l1 != null) {
                tmp += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                tmp += l2.val;
                l2 = l2.next;
            }
            ans.next = new ListNode(tmp % 10);
            cnt = tmp / 10;
            ans = ans.next;
        }
        if (cnt != 0) {
            ans.next = new ListNode(cnt);
        }
        return head.next;
    }
}