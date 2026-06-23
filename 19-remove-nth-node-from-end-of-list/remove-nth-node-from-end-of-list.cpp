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
        ListNode* temp=head;
        int l=0;
        while(temp){
            l++;
            temp=temp->next;
        }
        if (n == l) {
            ListNode* newHead = head->next;
            delete head; // Optional: free memory
            return newHead;
        }
        int id=l-n-1;
        temp=head;
        for(int i=0;i<id;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};