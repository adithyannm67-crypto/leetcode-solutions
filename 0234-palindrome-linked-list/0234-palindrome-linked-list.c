#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* p = head;
    int nums[100000];

    if (p == NULL) {
        return 0;
    }
    int i = 0;
    while (p != NULL) {
        nums[i++] = p->val;
        p = p->next;
    }

    int j = 0;
    int k = i - 1;
    int pal = 1;

    while (j < k) {
        if (nums[j++] != nums[k--]) {
            pal = 0;
        }
    }

    return pal;
}