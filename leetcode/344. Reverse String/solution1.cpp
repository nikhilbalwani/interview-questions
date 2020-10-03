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
    bool hasCycle(ListNode *head) {
        ListNode *o = head, *t = head;
        if(head == NULL)
        {
            return false;
        }
        while(true)
        {
            if(o->next != NULL)
            {
                o = o->next;
            }
            else
            {
                return false;
            }
            if(t->next != NULL and t->next->next != NULL)
            {
                t = t->next->next;
            }
            else
            {
                return false;
            }
            if(o == t)
            {
                return true;
            }

            }
            return false;
    }
};
