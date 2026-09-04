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
  ListNode* reverseList(ListNode* head)  {
        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Reverse the remaining list
        ListNode* newHead = reverseList(head->next);

        // Put current node after the next node
        ListNode* front = head->next;
        front->next = head;

        // Current node becomes the last node
        head->next = nullptr;

        return newHead;
    }
};