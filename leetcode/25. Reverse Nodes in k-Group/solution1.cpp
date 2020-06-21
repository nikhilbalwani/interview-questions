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

struct StartEndNextHead {
    ListNode *start;
    ListNode *end;
    ListNode *next_head;
};



class Solution {
public:
    
    bool check_links(ListNode *head, int k) {
        int cnt = k - 1;
        
        while (head -> next != NULL && cnt) {
            cnt -= 1;
            head = head->next;
        }
        
        return cnt == 0;
    }
    
    StartEndNextHead reverse(ListNode* head, int k) {
        StartEndNextHead ret;
        
        if (head == NULL) {
            ret.start = NULL;
            ret.end = NULL;
            ret.next_head = NULL;
            
            return ret;
        }
        
        if (!check_links(head, k)) {
            ret.start = head;
            ret.end = NULL;
            ret.next_head = NULL;
            
            return ret;
        }
        
        ListNode *left = head;
        ListNode *right = head->next;
        ListNode *save;
        
        ret.end = head;
        
        left->next = NULL;
        
        int cnt = k - 1;
        
        while (cnt-- && right != NULL) {
            save = right->next;
            right->next = left;
            
            left = right;
            right = save;
        }
        
        ret.start = left;
        ret.next_head = right;
        
        return ret;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *prev_start = NULL, *prev_end = NULL, *curr_start = NULL, *curr_end = NULL, *next_head = head, *ret_head = NULL;
        
        while (next_head != NULL) {
            StartEndNextHead pointer_group = reverse(next_head, k);
            curr_start = pointer_group.start;
            curr_end = pointer_group.end;
            next_head = pointer_group.next_head;
            
            if (prev_start == NULL) {
                ret_head = curr_start;
            }
            
            else  {
                prev_end->next = curr_start;
            }
            
            prev_start = curr_start;
            prev_end = curr_end;
        }
        
        return ret_head;
    }
};
