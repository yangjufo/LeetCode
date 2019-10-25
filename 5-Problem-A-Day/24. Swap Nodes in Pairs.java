/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy_head = new ListNode(0);        
        dummy_head.next = head;    
        ListNode prev = null;
        ListNode curr = head;        
        while (curr != null && head.next != null) {
            if (curr.next == null) {
                prev.next = curr;
                break;
            }
            ListNode tmp = curr.next.next;            
            curr.next.next = curr;            
            if (curr == head)
                head = curr.next;
            else
                prev.next = curr.next;
            curr.next = null;
            prev = curr;
            curr = tmp;
        }
        return head;
    }
}
