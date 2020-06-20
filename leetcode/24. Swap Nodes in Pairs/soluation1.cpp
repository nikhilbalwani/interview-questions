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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL or head -> next == NULL) {
            return head;
        }
        
        ListNode *first = head, *second = head -> next;
        ListNode *save = second -> next;
        
        second -> next = first;
        first -> next = save;
        head = second;
        
        while ( (first -> next != NULL && first -> next -> next != NULL) ) {
            ListNode *prev = first;
            first = first -> next;
            second = first -> next;
            save = second -> next;
            second -> next = first;
            first -> next = save;
            prev -> next = second;
        }
        
        return head;
    }
};
