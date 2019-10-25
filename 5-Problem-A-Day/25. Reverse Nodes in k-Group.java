/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy, curr = head;
        int count = 0;
        while (curr != null) {
            count += 1;
            if (count % k == 0) {                
                ListNode follow = curr.next;
                curr.next = null;
                prev.next = reverse(head);
                prev = head;
                head = follow;
                curr = head;
            }
            else 
                curr = curr.next;     
        }
        prev.next = head;
        return dummy.next;
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
}
