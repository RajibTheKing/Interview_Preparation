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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* ptr = head;
        while (ptr != nullptr && ptr->val == val)
        {
            ptr=ptr->next;
            head = ptr;
        }
        if (head == nullptr)
        {
            return nullptr;
        }

        ptr = head;
        ListNode* ref = head->next;

        while (ref != nullptr)
        {
            if (ref->val == val)
            {
                ptr->next = ref->next;
                ref = ptr->next;
            }
            else
            {
                ptr = ptr->next;
                ref = ref->next;
            }
        }
        return head;

    }
};