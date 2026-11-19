/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode *curr=head,*prev=NULL;

    while(curr!=NULL){

        if(prev&&prev->val==curr->val){
            prev->next=curr->next;
            curr=prev;
        }
        prev=curr;
        curr=curr->next;
    }

    return head;
    
}