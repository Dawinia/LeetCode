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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        int size = 0;
        ListNode* node = head;
        while(node != NULL) {
            node = node->next;
            ++size;
        }
        int half = size / 2;
        for(int i = 0; i < half; ++i) {
            head = head->next;
        }
        return head;
    }
};