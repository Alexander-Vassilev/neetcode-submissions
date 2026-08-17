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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* prevNode = nullptr;
        ListNode* temp = head->next;

        while (node) {
            node->next = prevNode;
            prevNode = node;
            node = temp;
            temp = node->next;
        }

        return prevNode;
    }
};
