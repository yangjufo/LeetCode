/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode first, second, firstPrev, secondPrev;
        first = second = firstPrev = secondPrev = null;
        while (head != null) {
            if (head.val < x) {
                if (first == null)
                    first = head;
                else
                    firstPrev.next = head;
                firstPrev = head;
            } else {
                if (second == null)
                    second = head;
                else
                    secondPrev.next = head;
                secondPrev = head;
            }
            head = head.next;
        }
        if (first == null)
            return second;
        if (second == null)
            return first;
        secondPrev.next = null;
        firstPrev.next = second;
        return first;
    }
}
