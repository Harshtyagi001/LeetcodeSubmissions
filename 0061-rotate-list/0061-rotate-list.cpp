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
    // for counting lenghth and making cycle as well
    int length(ListNode*&head,ListNode*mainHead){
        cout<<"calc length"<<endl;
        int ct=0;
        while(head->next!=NULL){
            head=head->next;
            ct++;
        }
        head->next=mainHead;
        head=head->next;
        return ct+1;
    }
    
    void breakCycle(ListNode*head,int len){
        // cout<<"breaking cycle"<<endl;
         for(int i=0;i<len-1;i++){
             head=head->next;
         }
         head->next=NULL;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        int n=length(head,head);
        k%=n;
        int pos=n-k;
        // cout<<"psd"<<endl;
        while(pos--){
            head=head->next;  // updating head to that position
        }

        breakCycle(head,n); // breaking the cycle after n size starting from this new head

        return head;   // return new head
    } 
};