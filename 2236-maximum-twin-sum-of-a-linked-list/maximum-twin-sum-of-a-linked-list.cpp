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
    int pairSum(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        map<int,int> m;
        int i=0;
        temp=head;
        while(i<=(len/2)-1){
            m[i]=temp->val;
            i++;
            temp=temp->next;
        }
        while(temp){
            m[len-1-i]+=temp->val;
            i++;
            temp=temp->next;
        }
        int ans=0;
        for(auto i:m){
            ans=max(ans,i.second);
        }
        return ans;
        
    }
};