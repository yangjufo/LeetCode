# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_head = ListNode(0)
        prev = dummy_head
        while l1 != None or l2 != None:
            if l1 != None and l2 != None:
                if l1.val < l2.val:                    
                    l3 = ListNode(l1.val)
                    l1 = l1.next
                else:
                    l3 = ListNode(l2.val)
                    l2 = l2.next
            elif l1 != None:
                l3 = ListNode(l1.val)
                l1 = l1.next
            else:
                l3 = ListNode(l2.val)
                l2 = l2.next
            prev.next = l3
            prev = prev.next
        return dummy_head.next