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
    map<ListNode*, bool> mp;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr = headA;
        while (ptr != nullptr)
        {
            mp[ptr] = true;
            ptr = ptr->next;
        }

        ptr = headB;
        while (ptr != nullptr)
        {
            if(mp.find(ptr) != mp.end())
            {
                return ptr;
            }
            ptr = ptr->next;
        }
        return nullptr;
    }
};