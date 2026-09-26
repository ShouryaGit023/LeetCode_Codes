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
        if (!head || !head->next) return;
        stack<ListNode*> s;
        ListNode* t=head;
        int c=0;
        while(t){
            s.push(t);
            t=t->next;
            c++;
        }
        c/=2;
        t=head;
        while(c--){
            ListNode* temp=s.top();
            s.pop();
            temp->next=t->next;
            t->next=temp;
            t=temp->next;
        }
        t->next=nullptr;
        


    }
};