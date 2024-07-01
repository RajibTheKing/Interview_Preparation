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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }

        int previousValue = head->val;
        ListNode* ptr = head;
        ListNode* ref = head->next;

        while (ref != nullptr)
        {
            if (ref->val == previousValue)
            {
                ptr->next = ref->next;
                ref = ref->next;
            }
            else
            {
                ptr = ptr->next;
                ref = ref->next;
                previousValue = ptr->val;
            }
        }
        return head;
    }
};