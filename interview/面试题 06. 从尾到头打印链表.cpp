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
    vector<int> reversePrint(ListNode* head) {
        stack<int> list;
        vector<int> ans;
        while(head != NULL) {
            // list.push(head->val);
            ans.emplace_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        // while(!list.empty()) {
        //     ans.emplace_back(list.top());
        //     list.pop();
        // }
        return ans;
    }
};