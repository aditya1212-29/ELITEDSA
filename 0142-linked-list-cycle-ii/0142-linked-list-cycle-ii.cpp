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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode *node = head;
        unordered_map<ListNode*, bool>mp;
        mp[head] = 1;
        while(node != NULL){
            if(mp[node->next]) return node->next;
            mp[node->next] = 1;
            node = node->next;
        }
        return NULL;
    }
};