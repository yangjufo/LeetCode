# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
                
        if not head:
            return 
        temp = head 
        slow = head 
        fast = head 
        
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        if fast:
            slow = slow.next 
        
        stack = [] 
        
        while slow:
            stack.append(slow)
            slow = slow.next 
        
        slow = head 
        
        while stack:
            temp = slow.next 
            node = stack.pop()
            slow.next = node 
            node.next = temp 
            slow = temp 
        
        slow.next = None 