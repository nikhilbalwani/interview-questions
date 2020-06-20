/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummy = NULL;
        
        if (lists.size() == 0) {
            return dummy;
        }
        
        else if (lists.size() == 1) {
            return lists[0];
        }
        
        int range;
        
        if ((int) log2(lists.size()) == log2(lists.size())) {
            range = (int) log2(lists.size());
        }
        else {
            range = (int) log2(lists.size()) + 1;
        }
        
        int tot_range = range;
        range = pow(2, tot_range - 1);
        
        for (int i = 0; i < tot_range; ++i) {
            
            for (int j = 0; j < range; j += 1) {
                
                if (j + range >= lists.size()) {
                    break;
                }
                cout << j << " " << j + range << endl;
                lists[j] = mergeTwoLists(lists[j], lists[j + range]);
            }
            
            range /= 2;
        }
        
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        else if (l2 == NULL) {
            return l1;
        }
        
        ListNode *ref, *ret;
        
        if (l1 -> val < l2 -> val) {
            ref = l1;
            l1 = l1 -> next;
        }
        else {
            ref = l2;
            l2 = l2 -> next;
        }
        
        
        ret = ref;
        
        while (! (l1 == NULL && l2 == NULL) ) {
            if (l1 == NULL) {
                ref -> next = l2;
                break;
            }
            else if (l2 == NULL) {
                ref -> next = l1;
                break;
            }
            
            else if (l1 -> val < l2 -> val) {
                ref -> next = l1;
                l1 = l1 -> next;
            }
            
            else {
                ref -> next = l2;
                l2 = l2 -> next;
            }
            
            ref = ref -> next;
        }
        
        return ret;
    }
};
