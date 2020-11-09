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
        ListNode l3 = new ListNode(0);
        ListNode prev = l3;
        int tmp = 0;
        while (l1 != null || l2 != null) {
            if (l1 != null) {
                tmp += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                tmp += l2.val;
                l2 = l2.next;
            }            
            prev.next = new ListNode(tmp % 10);
            prev = prev.next;
            tmp /= 10;
        }        
        if (tmp != 0) {
            prev.next = new ListNode(tmp % 10);
            prev = prev.next;
        }            
        return l3.next;    
    }
}