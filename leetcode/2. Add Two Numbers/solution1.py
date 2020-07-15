# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        carry = 0
        
        out = ListNode()
        ret = out
        
        while True:
            
            if l1 != None and l2 != None:
                curr_add = l1.val + l2.val + carry
                out.val = curr_add % 10
                carry = curr_add // 10
                
                l1 = l1.next
                l2 = l2.next
            
            elif l1 == None and l2 != None:
                curr_add = l2.val + carry
                out.val = curr_add % 10
                carry = curr_add // 10
                
                l2 = l2.next
            
            elif l2 == None and l1 != None:
                curr_add = l1.val + carry
                out.val = curr_add % 10
                carry = curr_add // 10
                
                l1 = l1.next
            
            if l1 == None and l2 == None:
                if carry == 0:
                    return ret
                else:
                    out.next = ListNode()
                    out = out.next
                    out.val = carry
                    return ret
                
            out.next = ListNode()
            out = out.next
