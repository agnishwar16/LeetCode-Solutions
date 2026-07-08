class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Step 1: Find length of the list
        int length = 0;
        ListNode* countPtr = head;
        while (countPtr != nullptr) {
            length++;
            countPtr = countPtr->next;
        }

        // Step 2: Reverse using for loop
        ListNode* before = nullptr;
        ListNode* temp = head;
        ListNode* after = nullptr;

        for (int i = 0; i < length; i++) {
            after = temp->next;   // Save next
            temp->next = before;  // Reverse pointer
            before = temp;        // Move "before" forward
            temp = after;         // Move "temp" forward
        }

        return before; // New head
    }
};
