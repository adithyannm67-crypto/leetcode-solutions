#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     struct TreeNode *left;
     *     struct TreeNode *right;
     * };
     */
    if (root == NULL) {
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    struct TreeNode *p = root, *prev = NULL;

    while (p != NULL) {
        prev = p;
        if (val < p->val) {
            p = p->left;
            if (p == NULL) {
                struct TreeNode* new =
                    (struct TreeNode*)malloc(sizeof(struct TreeNode));
                new->val = val;
                new->left = NULL;
                new->right = NULL;
                prev->left = new;
                return root;
            }
        } else if (val > p->val) {
            p = p->right;
            if (p == NULL) {
                struct TreeNode* new =
                    (struct TreeNode*)malloc(sizeof(struct TreeNode));
                new->val = val;
                new->left = NULL;
                new->right = NULL;
                prev->right = new;
                return root;
            }
        }
    }
    return NULL;
}