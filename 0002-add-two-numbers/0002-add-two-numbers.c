/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1, *p2 = l2;
    int carry = 0;
    struct ListNode *sumHead = NULL, *prev = NULL;
    while (p1 != NULL || p2 != NULL||carry==1) {
        struct ListNode* temp =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        int operand1 = 0, operand2 = 0;
        if (p1 != NULL) {
            operand1 = p1->val;
        }
        if (p2 != NULL) {
            operand2 = p2->val;
        }
        int sum = carry + operand1 + operand2;

        if (sum >= 10) {
            sum = sum % 10;
            carry =1;
        }else{
            carry=0;
        }
        temp->val = sum;
        temp->next = NULL;
        if (sumHead == NULL) {
            sumHead = temp;
        } else {
            prev->next = temp;
        }
        if (p1 != NULL)
            p1 = p1->next;
        if (p2 != NULL)
            p2 = p2->next;
        prev = temp;
    }

    return sumHead;
}