class Solution {
public:
    // Reverse function
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head) return head;

        // Step 1: Reverse the list
        head = reverse(head);

        // Step 2: Remove nodes smaller than max so far
        ListNode* curr = head;
        int maxSoFar = curr->val;

        while (curr && curr->next) {
            if (curr->next->val < maxSoFar) {
                curr->next = curr->next->next;

            } else {
                curr = curr->next;
                maxSoFar = curr->val;
            }
        }

        // Step 3: Reverse back
        head = reverse(head);

        return head;
    }
};
