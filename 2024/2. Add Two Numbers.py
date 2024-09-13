# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        head = None
        prev = None
        while l1 is not None or l2 is not None or carry > 0:
            sum = carry
            if l1 is not None:
                sum += l1.val
                l1 = l1.next
            if l2 is not None:
                sum += l2.val
                l2 = l2.next
            curr = ListNode(sum % 10)
            carry = sum // 10
            if head is None:
                head = curr
            else:
                prev.next = curr
            prev = curr
        return head
