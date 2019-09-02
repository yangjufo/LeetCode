# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head        
        slow = fast = dummy
        for i in range(n + 1):
            fast = fast.next
        while fast != None:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return dummy.next