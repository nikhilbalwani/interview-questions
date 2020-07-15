# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        curr_sum = 0
        ret = ListNode()
        ptr = ret
        
        while l1 or l2 or curr_sum:
            if l1:
                curr_sum += l1.val
                l1 = l1.next
            
            if l2:
                curr_sum += l2.val
                l2 = l2.next
                
            ret.next = ListNode(curr_sum % 10)
            ret = ret.next
            curr_sum //= 10
            
        return ptr.next
