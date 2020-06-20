/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ref, *ret;
        
        if (l1 == NULL) {
            return l2;
        }
        
        else if (l2 == NULL) {
            return l1;
        }
        
        if (l1 -> val < l2 -> val) {
            ref = l1;
            l1 = l1 -> next;
        }
        
        else {
            ref = l2;
            l2 = l2 -> next;
        }
        
        ret = ref;
        
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                ref -> next = l2;
                l2 = l2 -> next;
                ref = ref -> next;
            }
            
            else if (l2 == NULL) {
                ref -> next = l1;
                l1 = l1 -> next;
                ref = ref -> next;
            }
            
            else if (l1 -> val <= l2 -> val) {
                ref -> next = l1;
                l1 = l1 -> next;
                ref = ref -> next;
            }
            else {
                ref -> next = l2;
                l2 = l2 -> next;
                ref = ref -> next;
            }
        }
        
        return ret;
    }
};
