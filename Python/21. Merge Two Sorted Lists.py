# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = ListNode(0)
        pre = l3
        while l1 != None or l2 != None:
            if l1 == None:
                curr = l2
                l2 = l2.next
            elif l2 == None:
                curr = l1
                l1 = l1.next
            elif l1.val < l2.val:
                curr = l1
                l1 = l1.next
            else:
                curr = l2
                l2 = l2.next
            pre.next = curr
            pre = curr
        return l3.next
