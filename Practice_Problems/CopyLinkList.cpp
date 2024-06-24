/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* ptr = head;
        Node* newHead = nullptr;
        Node* newPtr = nullptr;
        while(ptr != nullptr)
        {
            Node* newNode = new Node(ptr->val);

            if(newHead == nullptr)
            {
                newHead = newNode;
                newPtr = newNode;
            }
            else
            {
                newPtr->next = newNode;
                newPtr = newNode;
            }
            mp[ptr] = newNode;
            ptr = ptr->next;
        }
        ptr = head;
        newPtr = newHead;
        while(ptr != nullptr)
        {
            newPtr->random = mp[ptr->random];
            ptr = ptr->next;
            newPtr=newPtr->next;
        }
        return newHead;
    }
};