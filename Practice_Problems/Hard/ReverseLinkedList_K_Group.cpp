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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
        {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prevRef = dummy;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while(isAvailable(ptr1, k) && ptr2 != nullptr)
        {
            int cnt = k-1;
            while(cnt--)
            {
                ListNode* nextRef = ptr2->next;
                ptr2->next = prevRef->next;
                prevRef->next = ptr2;
                ptr2 = nextRef;
                ptr1->next = nextRef;
            }

            prevRef = ptr1;
            ptr1 = prevRef->next;
            ptr2 = nullptr;
            if(ptr1 != nullptr)
                ptr2 = ptr1->next;
        }
        return dummy->next;
    }

    bool isAvailable(ListNode* ptr, int k)
    {
        while (ptr != nullptr && k > 0)
        {
            k--;
            ptr = ptr->next;
        }

        return k == 0;
    }
};