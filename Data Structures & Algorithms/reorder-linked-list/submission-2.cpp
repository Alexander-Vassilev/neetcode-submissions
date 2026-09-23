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
    void reorderList(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* prev = nullptr;

        while (ptr2) {
            ptr2 = ptr2->next;
            if (ptr2) ptr2 = ptr2->next;
            prev = ptr1;
            ptr1 = ptr1->next;
        }

        prev->next = nullptr;

        while (ptr1) {
            ListNode* temp = ptr1->next;
            ptr1->next = prev;
            prev = ptr1;
            ptr1 = temp;
        }

        while (prev && head) {
            ListNode* headNext = head->next;
            ListNode* prevNext = prev->next;
            head->next = prev;
            prev->next = headNext;
            head = headNext;
            prev = prevNext;
        }
    }
};
