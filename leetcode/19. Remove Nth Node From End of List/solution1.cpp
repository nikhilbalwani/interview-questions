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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pointer1 = head, *pointer2 = head, *prev_pointer2 = nullptr;
        
        if (head == nullptr) {
            return head;
        }
        
        if (head -> next == nullptr && n == 1) {
            return nullptr;
        }
        
        for (int i = 0; i < n - 1; ++i) {
            if (pointer1 -> next == nullptr) {
                return head;
            }
            
            pointer1 = pointer1 -> next;
        }
        
        while (pointer1 -> next != nullptr) {
            pointer1 = pointer1 -> next;
            prev_pointer2 = pointer2;
            pointer2 = pointer2 -> next;
        }
        
        if (prev_pointer2 == nullptr) {
            return pointer2 -> next;
        }
        
        prev_pointer2 -> next = pointer2 -> next;
        
        return head;
    }
};
