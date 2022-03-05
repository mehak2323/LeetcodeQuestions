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
    void deleteNode(ListNode* node) {
        
        //free up space solution
        ListNode* next = node->next;
        *node = *next;
        delete next;
        
        //Another solution
        //*node = *(node->next);

        //What I wrote
        //node->val=node->next->val;
        //node->next=node->next->next;
    }
};