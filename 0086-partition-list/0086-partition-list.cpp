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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = new ListNode(0);
        ListNode* bigHead   = new ListNode(0);

        ListNode* smallTail = smallHead;
        ListNode* bigTail   = bigHead;

        ListNode* curr = head;
        while(curr){
            ListNode *nextNode=curr->next;

            if (curr->val<x){
                smallTail->next=curr;
                smallTail=curr;
            }
            else{
                bigTail->next=curr;
                bigTail=curr;
            }
            curr=nextNode;
        }
        smallTail->next=bigHead->next;
        bigTail->next=nullptr;
        return smallHead->next;

    
    }
};