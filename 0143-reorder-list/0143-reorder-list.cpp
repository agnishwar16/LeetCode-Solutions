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
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;

        }
        
        ListNode *secondHalf=slow->next;
        slow->next=nullptr;

        ListNode *prev = nullptr;
        ListNode *curr = secondHalf;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* mergeS=prev;
        ListNode* mergef=head;

        while(mergeS&&mergef){

            ListNode* firstNext = mergef->next;
            ListNode* secondNext = mergeS->next;  

            mergef->next=mergeS;
            mergeS->next=firstNext;

            mergef = firstNext;
            mergeS = secondNext;
            
        }
    }
};