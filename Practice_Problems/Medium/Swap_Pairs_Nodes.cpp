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
        if (head == nullptr)
        {
            return head;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ListNode* ref = nullptr;

        while(ptr2 != nullptr)
        {
            if (ptr1 == head)
            {
                ptr1->next = ptr2->next;
                ptr2->next = ptr1;
                head = ptr2;
            }
            else
            {
                ref->next = ptr2;
                ptr1->next = ptr2->next;
                ptr2->next = ptr1;
            }

            ref = ptr1;
            ptr1 = ptr1->next;
            ptr2 = nullptr;
            if (ptr1 != nullptr)
            {
                ptr2 = ptr1->next;
            }
        }

        return head;
    }
};