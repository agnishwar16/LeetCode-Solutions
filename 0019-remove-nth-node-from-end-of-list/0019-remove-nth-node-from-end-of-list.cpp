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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *temp=head;
        for (int i=0;i<n;i++){
            if (fast==nullptr){
                return nullptr;
            }
            fast=fast->next;

        }while(fast){
            temp=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if (slow==head){
            head=head->next;
        }else{
            temp->next = slow->next;
        }
        delete slow;
        return head;
    }
};